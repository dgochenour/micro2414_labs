
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#ifndef rti_me_cpp_hxx
#include "rti_me_cpp.hxx"
#endif

#include "wh_sm/wh_sm_history.h"
#include "rh_sm/rh_sm_history.h"

#include "example.h"
#include "exampleSupport.h"
#include "examplePlugin.h"

#include "exampleApplication.h"

using namespace DDS;

class PoseReaderListener : public DataReaderListener
{
  public:

    DDS_Long total_samples;

    PoseReaderListener()
    {
        total_samples = 0;
    }

    // LAB #3 -- add a callback for incompatible QoS
    virtual void on_requested_incompatible_qos(DDSDataReader *reader, 
            const DDS_RequestedIncompatibleQosStatus &status); 

    virtual void on_data_available(DataReader *reader);

    virtual void on_subscription_matched(
        DataReader *writer,
        const SubscriptionMatchedStatus& status)
    {
        if (status.current_count_change > 0)
        {
            printf("Matched a publisher\n");
        }
        else if (status.current_count_change < 0)
        {
            printf("Unmatched a publisher\n");
        }
    }
};

// LAB #3 -- implement the callback 
void PoseReaderListener::on_requested_incompatible_qos(
        DDSDataReader *reader, 
        const DDS::RequestedIncompatibleQosStatus &status) {
      
    std::cout << "Incompatible QoS! Count: " << status.total_count << std::endl;
    std::cout << "Last Offending Policy: " << status.last_policy_id << std::endl;
}

template <typename T>
void take_and_print(typename T::DataReader* reader, Long *total_samples)
{
    PoseSeq data_seq;
    SampleInfoSeq info_seq;
    ReturnCode_t retcode;
    int i;

    retcode = reader->take(
        data_seq,
        info_seq,
        LENGTH_UNLIMITED,
        ANY_SAMPLE_STATE,
        ANY_VIEW_STATE,
        ANY_INSTANCE_STATE);

    if (retcode != RETCODE_OK)
    {
        printf("failed to take data, retcode(%d)\n", retcode);
        goto done;
    }

    for (i = 0; i < data_seq.length(); ++i)
    {
        if (!info_seq[i].valid_data)
        {
            printf("Got metadata. Instance State: %d.\n",
            info_seq[i].instance_state);
        }
        else
        {
            Pose *sample;

            sample = data_seq.get_reference(i);
            printf("INFO: Data received.\n");
            std::cout << "\tobj_id = " << sample->obj_id << std::endl;
            std::cout << "\tposition.x = " << sample->position.x << std::endl;
            std::cout << "\tposition.y = " << sample->position.y << std::endl;
            std::cout << "\tposition.z = " << sample->position.z << std::endl;
            (*total_samples)++;
        }
    }

    /* Return the loaned data */
    reader->return_loan(data_seq, info_seq);

    done:
    PoseSeq_finalize(&data_seq); 
}

void
PoseReaderListener::on_data_available(DataReader *reader)
{
    PoseDataReader *hw_reader = PoseDataReader::narrow(reader);
    take_and_print<Pose>(hw_reader, &total_samples);
}

int
subscriber_main_w_args(
    Long domain_id,
    char *udp_intf,
    char *peer,
    Long sleep_time,
    Long count)
{
    Subscriber *subscriber = NULL;
    DataReader *datareader = NULL;
    DataReaderQos dr_qos;
    ReturnCode_t retcode;
    Application *application;
    PoseReaderListener listener;

    int ret_value = -1;

    application = new Application();
    if (application == NULL)
    {
        printf("failed Application new\n");
        goto done;
    }

    retcode = application->initialize(
        "subscriber", 
        "publisher", 
        domain_id,
        udp_intf, 
        peer, 
        sleep_time, 
        count);
    if (retcode != RETCODE_OK)
    {
        printf("failed Application initialize\n");
        goto done;
    }

    subscriber = application->participant->create_subscriber(
        SUBSCRIBER_QOS_DEFAULT,NULL,
        STATUS_MASK_NONE);
    if (subscriber == NULL)
    {
        printf("subscriber == NULL\n");
        goto done;
    }

    retcode = subscriber->get_default_datareader_qos(dr_qos);
    if (retcode != RETCODE_OK)
    {
        printf("failed get_default_datareader_qos\n");
        goto done;
    }

    dr_qos.resource_limits.max_samples = 32;
    dr_qos.resource_limits.max_instances = 1;
    dr_qos.resource_limits.max_samples_per_instance = 32;
    /* if there are more remote writers, you need to increase these limits */
    dr_qos.reader_resource_limits.max_remote_writers = 10;
    dr_qos.reader_resource_limits.max_remote_writers_per_instance = 10;
    dr_qos.history.depth = 32;

    /* Reliability QoS */
    #ifdef USE_RELIABLE_QOS
    dr_qos.reliability.kind = RELIABLE_RELIABILITY_QOS;
    #else
    dr_qos.reliability.kind = BEST_EFFORT_RELIABILITY_QOS;
    #endif

    // LAB #3 -- add a deadline to DataReader 
    dr_qos.deadline.period.sec = 0;
    dr_qos.deadline.period.nanosec = 500000000; // .5s

    datareader = subscriber->create_datareader(
        application->topic,
        dr_qos,
        &listener,
        DATA_AVAILABLE_STATUS | 
        DDS_SUBSCRIPTION_MATCHED_STATUS | 
        DDS_REQUESTED_INCOMPATIBLE_QOS_STATUS);

    if (datareader == NULL)
    {
        printf("datareader == NULL\n");
        goto done;
    }

    for (int i = 0; (application->count <= 0) || (i < application->count); ++i)
    {
        printf("Subscriber sleeping for %d msec...\n", application->sleep_time);

        OSAPI_Thread_sleep(application->sleep_time);
    }

    ret_value = 0;

    done:

    if (application != NULL)
    {
        delete application;
    }

    if (ret_value == 0)
    {
        printf("Samples received %d\n", listener.total_samples);
        if (listener.total_samples == 0)
        {
            return -1;
        }
    }

    return ret_value;
}

#if !(defined(RTI_VXWORKS) && !defined(__RTP__))
int
main(int argc, char **argv)
{
    Long i = 0;
    Long domain_id = 0;
    char *peer = NULL;
    char *udp_intf = NULL;
    Long sleep_time = 1000;
    Long count = 0;

    for (i = 1; i < argc; ++i)
    {
        if (!strcmp(argv[i], "-domain"))
        {
            ++i;
            if (i == argc)
            {
                printf("-domain <domain_id>\n");
                return -1;
            }
            domain_id = strtol(argv[i], NULL, 0);
        }
        else if (!strcmp(argv[i], "-udp_intf"))
        {
            ++i;
            if (i == argc)
            {
                printf("-udp_intf <interface>\n");
                return -1;
            }
            udp_intf = argv[i];
        }
        else if (!strcmp(argv[i], "-peer"))
        {
            ++i;
            if (i == argc)
            {
                printf("-peer <address>\n");
                return -1;
            }
            peer = argv[i];
        }
        else if (!strcmp(argv[i], "-sleep"))
        {
            ++i;
            if (i == argc)
            {
                printf("-sleep_time <sleep_time>\n");
                return -1;
            }
            sleep_time = strtol(argv[i], NULL, 0);
        }
        else if (!strcmp(argv[i], "-count"))
        {
            ++i;
            if (i == argc)
            {
                printf("-count <count>\n");
                return -1;
            }
            count = strtol(argv[i], NULL, 0);
        }
        else if (!strcmp(argv[i], "-h"))
        {
            Application::help(argv[0]);
            return 0;
        }
        else
        {
            printf("unknown option: %s\n", argv[i]);
            return -1;
        }
    }

    return subscriber_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
#elif defined(RTI_VXWORKS)
int
subscriber_main(void)
{
    /* Explicitly configure args below */
    Long domain_id = 0;
    char *peer = "127.0.0.1";
    char *udp_intf = NULL;
    Long sleep_time = 1000;
    Long count = 0;

    return subscriber_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
#endif
