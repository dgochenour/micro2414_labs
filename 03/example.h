/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from example.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#ifndef example_1944007933_h
#define example_1944007933_h

#ifndef rti_me_cpp_hxx
#include "rti_me_cpp.hxx"
#endif

#if (defined(RTI_WIN32) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

static const char * const location_topic_name = "Object Location";

struct PointSeq;

class Point  
{
  public:
    typedef struct PointSeq Seq;

    CDR_Double x;
    CDR_Double y;
    CDR_Double z;

};

#define REDA_SEQUENCE_USER_API
#define T Point
#define TSeq PointSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

#define REDA_SEQUENCE_USER_API
#define T Point
#define TSeq PointSeq
#define REDA_SEQUENCE_EXCLUDE_STRUCT
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

NDDSUSERDllExport extern RTI_BOOL
Point_initialize(Point* sample);

NDDSUSERDllExport extern Point*
Point_create(void);

#ifndef RTI_CERT
NDDSUSERDllExport extern RTI_BOOL
Point_finalize(Point* sample);

NDDSUSERDllExport extern void
Point_delete(Point* sample);
#endif

NDDSUSERDllExport extern RTI_BOOL
Point_copy(Point* dst, const Point* src);

struct QuaternionSeq;

class Quaternion  
{
  public:
    typedef struct QuaternionSeq Seq;

    CDR_Double x;
    CDR_Double y;
    CDR_Double z;
    CDR_Double w;

};

#define REDA_SEQUENCE_USER_API
#define T Quaternion
#define TSeq QuaternionSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

#define REDA_SEQUENCE_USER_API
#define T Quaternion
#define TSeq QuaternionSeq
#define REDA_SEQUENCE_EXCLUDE_STRUCT
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

NDDSUSERDllExport extern RTI_BOOL
Quaternion_initialize(Quaternion* sample);

NDDSUSERDllExport extern Quaternion*
Quaternion_create(void);

#ifndef RTI_CERT
NDDSUSERDllExport extern RTI_BOOL
Quaternion_finalize(Quaternion* sample);

NDDSUSERDllExport extern void
Quaternion_delete(Quaternion* sample);
#endif

NDDSUSERDllExport extern RTI_BOOL
Quaternion_copy(Quaternion* dst, const Quaternion* src);

struct PoseSeq;
class PoseTypeSupport;
class PoseDataWriter;
class PoseDataReader;

class Pose  
{
  public:
    typedef struct PoseSeq Seq;
    typedef PoseTypeSupport TypeSupport;
    typedef PoseDataWriter DataWriter;
    typedef PoseDataReader DataReader;

    CDR_Long obj_id;
    Point position;
    Quaternion orientation;

};

NDDSUSERDllExport extern const char *PoseTYPENAME;

#define REDA_SEQUENCE_USER_API
#define T Pose
#define TSeq PoseSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

#define REDA_SEQUENCE_USER_API
#define T Pose
#define TSeq PoseSeq
#define REDA_SEQUENCE_EXCLUDE_STRUCT
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

NDDSUSERDllExport extern RTI_BOOL
Pose_initialize(Pose* sample);

NDDSUSERDllExport extern Pose*
Pose_create(void);

#ifndef RTI_CERT
NDDSUSERDllExport extern RTI_BOOL
Pose_finalize(Pose* sample);

NDDSUSERDllExport extern void
Pose_delete(Pose* sample);
#endif

NDDSUSERDllExport extern RTI_BOOL
Pose_copy(Pose* dst, const Pose* src);

#if (defined(RTI_WIN32) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* example */

