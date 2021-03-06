
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

class PoseDataWriterListener : public DataWriterListener
{
  public:
    PoseDataWriterListener() : DataWriterListener() { }
    ~PoseDataWriterListener() { }

    virtual void on_publication_matched(
        DataWriter *writer,
        const PublicationMatchedStatus& status)
    {
        if (status.current_count_change > 0)
        {
            printf("Matched a subscriber\n");
        }
        else if (status.current_count_change < 0)
        {
            printf("Unmatched a subscriber\n");
        }
    }
};

int
publisher_main_w_args(
    Long domain_id,
    char *udp_intf,
    char *peer,
    Long sleep_time,
    Long count)
{
    Application *application;
    Publisher *publisher = NULL;
    DataWriter *datawriter = NULL;
    PoseDataWriter *hw_writer = NULL;
    DataWriterQos dw_qos;
    ReturnCode_t retcode;
    Pose *sample = NULL;
    Long i;
    PoseDataWriterListener dw_listener;
    int ret_value = -1;

    sample = PoseTypeSupport::create_data();
    if (sample == NULL)
    {
        printf("failed Pose_create\n");
        goto done;
    }

    application = new Application();
    if (application == NULL)
    {
        printf("failed Application new\n");
        goto done;
    }

    retcode = application->initialize(
        "publisher", 
        "subscriber", 
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

    publisher = application->participant->create_publisher(
        PUBLISHER_QOS_DEFAULT,
        NULL,
        STATUS_MASK_NONE);
    if (publisher == NULL)
    {
        printf("publisher == NULL\n");
        goto done;
    }

    retcode = publisher->get_default_datawriter_qos(dw_qos);
    if (retcode != RETCODE_OK)
    {
        printf("failed get_default_datawriter_qos\n");
        goto done;
    }

    #ifdef USE_RELIABLE_QOS
    dw_qos.reliability.kind = RELIABLE_RELIABILITY_QOS;
    #else
    dw_qos.reliability.kind = BEST_EFFORT_RELIABILITY_QOS;
    #endif
    dw_qos.resource_limits.max_samples = 32;
    dw_qos.resource_limits.max_samples_per_instance = 32;
    dw_qos.resource_limits.max_instances = 1;
    dw_qos.history.depth = 32;

    datawriter = publisher->create_datawriter(
        application->topic,
        dw_qos,
        &dw_listener,
        DDS_PUBLICATION_MATCHED_STATUS);
    if (datawriter == NULL)
    {
        printf("datawriter == NULL\n");
        goto done;
    }

    hw_writer = PoseDataWriter::narrow(datawriter);
    if (hw_writer == NULL)
    {
        printf("failed datawriter narrow\n");
        goto done;
    }

    /* TODO set sample attributes here or inside the for loop (or both) */
    sample->obj_id = 20; // LAB #2 -- this is just an arbitrary ID

    for (i = 0; (application->count == 0) || (i < application->count); ++i)
    {

        sample->position.x = sin(i);
        sample->position.y = cos(i);
        sample->position.z = sin(i*3);
        retcode = hw_writer->write(*sample, HANDLE_NIL);
        if (retcode != RETCODE_OK)
        {
            printf("Failed to write sample\n");
        } 
        else
        {
            printf("Written sample %d\n",(i+1));
        }

        OSAPI_Thread_sleep(application->sleep_time);
    }

    ret_value = 0;

    done:

    if (application != NULL)
    {
        delete application;
    }

    if (sample != NULL)
    {
        PoseTypeSupport::delete_data(sample);
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

    return publisher_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
#elif defined(RTI_VXWORKS)
int
publisher_main(void)
{
    /* Explicitly configure args below */
    Long domain_id = 0;
    char *peer = "127.0.0.1";
    char *udp_intf = NULL;
    Long sleep_time = 1000;
    Long count = 0;

    return publisher_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
#endif
