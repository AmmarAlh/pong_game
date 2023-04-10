// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from advanced_user_interface:msg/Point2.idl
// generated code does not contain a copyright notice

#ifndef ADVANCED_USER_INTERFACE__MSG__DETAIL__POINT2__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define ADVANCED_USER_INTERFACE__MSG__DETAIL__POINT2__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "advanced_user_interface/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "advanced_user_interface/msg/detail/point2__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace advanced_user_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_advanced_user_interface
cdr_serialize(
  const advanced_user_interface::msg::Point2 & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_advanced_user_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  advanced_user_interface::msg::Point2 & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_advanced_user_interface
get_serialized_size(
  const advanced_user_interface::msg::Point2 & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_advanced_user_interface
max_serialized_size_Point2(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace advanced_user_interface

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_advanced_user_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, advanced_user_interface, msg, Point2)();

#ifdef __cplusplus
}
#endif

#endif  // ADVANCED_USER_INTERFACE__MSG__DETAIL__POINT2__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
