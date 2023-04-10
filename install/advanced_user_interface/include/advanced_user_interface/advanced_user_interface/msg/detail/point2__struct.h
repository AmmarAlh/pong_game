// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from advanced_user_interface:msg/Point2.idl
// generated code does not contain a copyright notice

#ifndef ADVANCED_USER_INTERFACE__MSG__DETAIL__POINT2__STRUCT_H_
#define ADVANCED_USER_INTERFACE__MSG__DETAIL__POINT2__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Point2 in the package advanced_user_interface.
typedef struct advanced_user_interface__msg__Point2
{
  double x;
  double y;
} advanced_user_interface__msg__Point2;

// Struct for a sequence of advanced_user_interface__msg__Point2.
typedef struct advanced_user_interface__msg__Point2__Sequence
{
  advanced_user_interface__msg__Point2 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} advanced_user_interface__msg__Point2__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ADVANCED_USER_INTERFACE__MSG__DETAIL__POINT2__STRUCT_H_
