/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from example.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#ifndef examplePlugin_1944007933_h
#define examplePlugin_1944007933_h

#include "example.h"

#if (defined(RTI_WIN32) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern RTI_BOOL 
Point_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param);

NDDSUSERDllExport extern RTI_BOOL 
Point_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param);

NDDSUSERDllExport extern RTI_UINT32
Point_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param);
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern RTI_BOOL 
Point_cdr_serialize_key(
    struct CDR_Stream_t *keystream, const void *sample,
    void *param);

NDDSUSERDllExport extern RTI_BOOL 
Point_cdr_deserialize_key(
    struct CDR_Stream_t *keystream, void *sample,
    void *param);

NDDSUSERDllExport extern RTI_UINT32
Point_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param);

NDDSUSERDllExport extern RTI_BOOL 
Point_instance_to_keyhash(
    struct NDDS_Type_Plugin *plugin,
    struct CDR_Stream_t *stream, DDS_KeyHash_t *keyHash, const void *instance,
    void *param);

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern RTI_BOOL 
Quaternion_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param);

NDDSUSERDllExport extern RTI_BOOL 
Quaternion_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param);

NDDSUSERDllExport extern RTI_UINT32
Quaternion_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param);
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern RTI_BOOL 
Quaternion_cdr_serialize_key(
    struct CDR_Stream_t *keystream, const void *sample,
    void *param);

NDDSUSERDllExport extern RTI_BOOL 
Quaternion_cdr_deserialize_key(
    struct CDR_Stream_t *keystream, void *sample,
    void *param);

NDDSUSERDllExport extern RTI_UINT32
Quaternion_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param);

NDDSUSERDllExport extern RTI_BOOL 
Quaternion_instance_to_keyhash(
    struct NDDS_Type_Plugin *plugin,
    struct CDR_Stream_t *stream, DDS_KeyHash_t *keyHash, const void *instance,
    void *param);

NDDSUSERDllExport extern struct NDDS_Type_Plugin*
PoseTypePlugin_get(void);
NDDSUSERDllExport extern const char*
PoseTypePlugin_get_default_type_name(void);
NDDSUSERDllExport extern NDDS_TypePluginKeyKind 
Pose_get_key_kind(
    struct NDDS_Type_Plugin *plugin,
    void *param);
/* --------------------------------------------------------------------------
Untyped interfaces to the typed sample management functions
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern RTI_BOOL
PosePlugin_create_sample(
    struct NDDS_Type_Plugin *plugin, void **sample,void *param);

#ifndef RTI_CERT
NDDSUSERDllExport extern RTI_BOOL 
PosePlugin_delete_sample(
    struct NDDS_Type_Plugin *plugin, void *sample,void *param);
#endif

NDDSUSERDllExport extern RTI_BOOL 
PosePlugin_copy_sample(
    struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param);
/* --------------------------------------------------------------------------
Typed-endpoint support for C++:
* -------------------------------------------------------------------------- */

NDDSUSERDllExport extern void* 
PosePlugin_create_typed_datawriter(
    void *writer);

#ifndef RTI_CERT
NDDSUSERDllExport extern void 
PosePlugin_delete_typed_datawriter(
    void *wrapper);
#endif

NDDSUSERDllExport extern void* 
PosePlugin_create_typed_datareader(
    void *reader);

#ifndef RTI_CERT
NDDSUSERDllExport extern void 
PosePlugin_delete_typed_datareader(
    void *wrapper);
#endif

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern RTI_BOOL 
Pose_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param);

NDDSUSERDllExport extern RTI_BOOL 
Pose_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param);

NDDSUSERDllExport extern RTI_UINT32
Pose_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param);
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern RTI_BOOL 
Pose_cdr_serialize_key(
    struct CDR_Stream_t *keystream, const void *sample,
    void *param);

NDDSUSERDllExport extern RTI_BOOL 
Pose_cdr_deserialize_key(
    struct CDR_Stream_t *keystream, void *sample,
    void *param);

NDDSUSERDllExport extern RTI_UINT32
Pose_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param);

NDDSUSERDllExport extern RTI_BOOL 
Pose_instance_to_keyhash(
    struct NDDS_Type_Plugin *plugin,
    struct CDR_Stream_t *stream, DDS_KeyHash_t *keyHash, const void *instance,
    void *param);

#if (defined(RTI_WIN32) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* examplePlugin_1944007933_h */

