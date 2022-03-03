/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from example.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#include "example.h"

#ifndef UNUSED_ARG
#define UNUSED_ARG(x) (void)(x)
#endif

/*** SOURCE_BEGIN ***/

/* ========================================================================= */

RTI_BOOL
Point_initialize(Point* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    CDR_Primitive_init_double(&sample->x);
    CDR_Primitive_init_double(&sample->y);
    CDR_Primitive_init_double(&sample->z);
    return RTI_TRUE;
}

Point *
Point_create(void)
{
    Point* sample;
    OSAPI_Heap_allocate_struct(&sample, Point);
    if (sample != NULL)
    {
        if (!Point_initialize(sample))
        {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
Point_finalize(Point* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

#ifndef RTI_CERT
void
Point_delete(Point* sample)
{
    if (sample != NULL)
    {
        /* Point_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        Point_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif
#endif

RTI_BOOL
Point_copy(Point* dst,const Point* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    CDR_Primitive_copy_double(&dst->x, &src->x);
    CDR_Primitive_copy_double(&dst->y, &src->y);
    CDR_Primitive_copy_double(&dst->z, &src->z);
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Point' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T Point
#define TSeq PointSeq
#define T_initialize Point_initialize
#define T_finalize   Point_finalize
#define T_copy       Point_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

#define REDA_SEQUENCE_USER_API
#define T Point
#define TSeq PointSeq
#include "dds_cpp/dds_cpp_sequence_defn.hxx"

/* ========================================================================= */

RTI_BOOL
Quaternion_initialize(Quaternion* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    CDR_Primitive_init_double(&sample->x);
    CDR_Primitive_init_double(&sample->y);
    CDR_Primitive_init_double(&sample->z);
    CDR_Primitive_init_double(&sample->w);
    return RTI_TRUE;
}

Quaternion *
Quaternion_create(void)
{
    Quaternion* sample;
    OSAPI_Heap_allocate_struct(&sample, Quaternion);
    if (sample != NULL)
    {
        if (!Quaternion_initialize(sample))
        {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
Quaternion_finalize(Quaternion* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

#ifndef RTI_CERT
void
Quaternion_delete(Quaternion* sample)
{
    if (sample != NULL)
    {
        /* Quaternion_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        Quaternion_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif
#endif

RTI_BOOL
Quaternion_copy(Quaternion* dst,const Quaternion* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    CDR_Primitive_copy_double(&dst->x, &src->x);
    CDR_Primitive_copy_double(&dst->y, &src->y);
    CDR_Primitive_copy_double(&dst->z, &src->z);
    CDR_Primitive_copy_double(&dst->w, &src->w);
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Quaternion' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T Quaternion
#define TSeq QuaternionSeq
#define T_initialize Quaternion_initialize
#define T_finalize   Quaternion_finalize
#define T_copy       Quaternion_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

#define REDA_SEQUENCE_USER_API
#define T Quaternion
#define TSeq QuaternionSeq
#include "dds_cpp/dds_cpp_sequence_defn.hxx"

/* ========================================================================= */

const char *PoseTYPENAME = "Pose";

RTI_BOOL
Pose_initialize(Pose* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    CDR_Primitive_init_long(&sample->obj_id);
    if (!Point_initialize(&sample->position))
    {
        return RTI_FALSE;
    }
    if (!Quaternion_initialize(&sample->orientation))
    {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

Pose *
Pose_create(void)
{
    Pose* sample;
    OSAPI_Heap_allocate_struct(&sample, Pose);
    if (sample != NULL)
    {
        if (!Pose_initialize(sample))
        {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
Pose_finalize(Pose* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    Point_finalize(&sample->position);
    Quaternion_finalize(&sample->orientation);
    return RTI_TRUE;
}

#ifndef RTI_CERT
void
Pose_delete(Pose* sample)
{
    if (sample != NULL)
    {
        /* Pose_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        Pose_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif
#endif

RTI_BOOL
Pose_copy(Pose* dst,const Pose* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    CDR_Primitive_copy_long(&dst->obj_id, &src->obj_id);
    if (!Point_copy(
        &dst->position, &src->position))
    {
        return RTI_FALSE;
    }
    if (!Quaternion_copy(
        &dst->orientation, &src->orientation))
    {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Pose' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T Pose
#define TSeq PoseSeq
#define T_initialize Pose_initialize
#define T_finalize   Pose_finalize
#define T_copy       Pose_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

#define REDA_SEQUENCE_USER_API
#define T Pose
#define TSeq PoseSeq
#include "dds_cpp/dds_cpp_sequence_defn.hxx"

