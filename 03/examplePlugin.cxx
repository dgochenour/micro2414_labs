/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from example.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#include "example.h"
#include "examplePlugin.h"
#include "exampleSupport.h"

/*** SOURCE_BEGIN ***/
#ifndef UNUSED_ARG
#define UNUSED_ARG(x) (void)(x)
#endif

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
RTI_BOOL 
Point_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    Point *sample = (Point *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_serialize_double(
        stream, &sample->x))
    {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_serialize_double(
        stream, &sample->y))
    {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_serialize_double(
        stream, &sample->z))
    {
        return RTI_FALSE;
    }  

    return RTI_TRUE;
}

RTI_BOOL 
Point_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    Point *sample = (Point *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_deserialize_double(
        stream, &sample->x))
    {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_deserialize_double(
        stream, &sample->y))
    {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_deserialize_double(
        stream, &sample->z))
    {
        return RTI_FALSE;
    }  

    return RTI_TRUE;

}

RTI_UINT32
Point_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    return  current_alignment - initial_alignment;
}
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
Point_cdr_serialize_key(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    return Point_cdr_serialize(stream, void_sample, param);
}

RTI_BOOL
Point_cdr_deserialize_key(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    return Point_cdr_deserialize(stream, void_sample, param);
}

RTI_UINT32
Point_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    return Point_get_serialized_sample_max_size(plugin, current_alignment, param);
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
RTI_BOOL 
Quaternion_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    Quaternion *sample = (Quaternion *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_serialize_double(
        stream, &sample->x))
    {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_serialize_double(
        stream, &sample->y))
    {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_serialize_double(
        stream, &sample->z))
    {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_serialize_double(
        stream, &sample->w))
    {
        return RTI_FALSE;
    }  

    return RTI_TRUE;
}

RTI_BOOL 
Quaternion_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    Quaternion *sample = (Quaternion *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_deserialize_double(
        stream, &sample->x))
    {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_deserialize_double(
        stream, &sample->y))
    {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_deserialize_double(
        stream, &sample->z))
    {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_deserialize_double(
        stream, &sample->w))
    {
        return RTI_FALSE;
    }  

    return RTI_TRUE;

}

RTI_UINT32
Quaternion_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    return  current_alignment - initial_alignment;
}
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
Quaternion_cdr_serialize_key(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    return Quaternion_cdr_serialize(stream, void_sample, param);
}

RTI_BOOL
Quaternion_cdr_deserialize_key(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    return Quaternion_cdr_deserialize(stream, void_sample, param);
}

RTI_UINT32
Quaternion_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    return Quaternion_get_serialized_sample_max_size(plugin, current_alignment, param);
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
RTI_BOOL 
Pose_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    Pose *sample = (Pose *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_serialize_long(
        stream, &sample->obj_id))
    {
        return RTI_FALSE;
    }  
    if(!Point_cdr_serialize(
        stream,
        &sample->position,
        param))
    {
        return RTI_FALSE;
    }
    if(!Quaternion_cdr_serialize(
        stream,
        &sample->orientation,
        param))
    {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

RTI_BOOL 
Pose_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    Pose *sample = (Pose *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_deserialize_long(
        stream, &sample->obj_id))
    {
        return RTI_FALSE;
    }  
    if(!Point_cdr_deserialize(
        stream,
        &sample->position,
        param))
    {
        return RTI_FALSE;
    }
    if(!Quaternion_cdr_deserialize(
        stream,
        &sample->orientation,
        param))
    {
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

RTI_UINT32
Pose_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment += CDR_get_max_size_serialized_long(
        current_alignment);

    current_alignment += Point_get_serialized_sample_max_size(
        plugin, current_alignment, param);

    current_alignment += Quaternion_get_serialized_sample_max_size(
        plugin, current_alignment, param);

    return  current_alignment - initial_alignment;
}
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */

RTI_BOOL
Pose_cdr_serialize_key(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    const Pose *sample = (Pose *)void_sample;
    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);
    if (!CDR_Stream_serialize_long(
        stream, &sample->obj_id))
    {
        return RTI_FALSE;
    }  

    return RTI_TRUE;
}

RTI_BOOL
Pose_cdr_deserialize_key(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    Pose *sample = (Pose *)void_sample;
    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);
    if (!CDR_Stream_deserialize_long(
        stream, &sample->obj_id))
    {
        return RTI_FALSE;
    }  

    return RTI_TRUE;
}

RTI_UINT32 
Pose_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment +=  CDR_get_max_size_serialized_long(
        current_alignment );

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------
Typed-endpoint support for C++:
* -------------------------------------------------------------------------- */

void* 
PosePlugin_create_typed_datawriter(
    void *writer)
{
    /* This function is only called from DDS_Publisher_create_datawriter
    so writer is guaranteed to have a valid (i.e. non-NULL) value */
    DDSDataWriter *cpp_writer = 
    new PoseDataWriter((DDS_DataWriter*)writer);
    return cpp_writer;   
}

#ifndef RTI_CERT
void 
PosePlugin_delete_typed_datawriter(
    void *wrapper)
{
    /* This function is only called from DDS_Publisher_create_datawriter
    * and DDS_Publisher_delete_datawriter so wrapper is guaranteed to have
    * a valid (i.e. non-NULL) value 
    */
    DDSDataWriter_impl *cpp_writer = (DDSDataWriter_impl *) wrapper;
    PoseDataWriter *t_writer  = 
    static_cast<PoseDataWriter *>(cpp_writer);
    delete t_writer;
}
#endif

void* 
PosePlugin_create_typed_datareader(
    void *reader)
{
    /* This function is only called from DDS_Subscriber_create_datareader
    * so reader is guaranteed to have a valid (i.e. non-NULL) value 
    */
    DDSDataReader *cpp_reader = 
    new PoseDataReader((DDS_DataReader*)reader);
    return cpp_reader;      
}

#ifndef RTI_CERT
void
PosePlugin_delete_typed_datareader(
    void *wrapper)
{
    /* This function is only called from DDS_Subscriber_create_datareader
    and DDS_Subscriber_delete_datareader so wrapper is guaranteed to have
    a valid (i.e. non-NULL) value */
    DDSDataReader_impl *cpp_reader = (DDSDataReader_impl *) wrapper;
    PoseDataReader *t_reader = 
    static_cast<PoseDataReader *>(cpp_reader);
    delete t_reader;
}
#endif

/* --------------------------------------------------------------------------
*  Sample Support functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
PosePlugin_create_sample(
    struct NDDS_Type_Plugin *plugin, void **sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    *sample = (void *) Pose_create();
    return (sample != NULL);
}

#ifndef RTI_CERT
RTI_BOOL
PosePlugin_delete_sample(
    struct NDDS_Type_Plugin *plugin, void *sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    /* Pose_delete() is a void function
    * which expects (sample != NULL). Since 
    * PosePlugin_delete_sample
    * is an internal function, sample is assumed to be a valid pointer 
    */ 
    Pose_delete((Pose *) sample);
    return RTI_TRUE;
}
#endif

RTI_BOOL 
PosePlugin_copy_sample(
    struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    return Pose_copy(
        (Pose *)dst,
        (const Pose *)src);
}
/* --------------------------------------------------------------------------
*  Type Pose Plugin Instantiation
* -------------------------------------------------------------------------- */

NDDSCDREncapsulation PoseEncapsulationKind[] =
{ {0,0} };

struct NDDS_Type_Plugin PoseTypePlugin =
{
    {0, 0},                     /* NDDS_Type_PluginVersion */
    NULL,                       /* DDS_TypeCode_t* */
    PoseEncapsulationKind,
    NDDS_TYPEPLUGIN_USER_KEY,   /* NDDS_TypePluginKeyKind */
    Pose_cdr_serialize,
    Pose_cdr_deserialize,
    Pose_get_serialized_sample_max_size,
    Pose_cdr_serialize_key,
    Pose_cdr_deserialize_key,
    Pose_get_serialized_key_max_size,
    PosePlugin_create_sample,
    #ifndef RTI_CERT
    PosePlugin_delete_sample,
    #else
    NULL,
    #endif
    PosePlugin_copy_sample,
    PluginHelper_get_key_kind,
    PluginHelper_instance_to_keyhash,
    PosePlugin_create_typed_datawriter,
    #ifndef RTI_CERT
    PosePlugin_delete_typed_datawriter,
    #else
    NULL,
    #endif
    PosePlugin_create_typed_datareader,
    #ifndef RTI_CERT
    PosePlugin_delete_typed_datareader
    #else
    NULL,
    #endif
};

/* --------------------------------------------------------------------------
*  Type Pose Plugin Methods
* -------------------------------------------------------------------------- */

struct NDDS_Type_Plugin *
PoseTypePlugin_get(void) 
{ 
    return &PoseTypePlugin;
} 

const char*
PoseTypePlugin_get_default_type_name(void) 
{ 
    return PoseTYPENAME;
} 

NDDS_TypePluginKeyKind 
Pose_get_key_kind(
    struct NDDS_Type_Plugin *plugin,
    void *param)
{
    UNUSED_ARG(param);
    UNUSED_ARG(plugin);
    return NDDS_TYPEPLUGIN_USER_KEY;
}

