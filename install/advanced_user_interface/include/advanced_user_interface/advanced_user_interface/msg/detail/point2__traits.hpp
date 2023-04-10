// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from advanced_user_interface:msg/Point2.idl
// generated code does not contain a copyright notice

#ifndef ADVANCED_USER_INTERFACE__MSG__DETAIL__POINT2__TRAITS_HPP_
#define ADVANCED_USER_INTERFACE__MSG__DETAIL__POINT2__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "advanced_user_interface/msg/detail/point2__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace advanced_user_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const Point2 & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Point2 & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Point2 & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace advanced_user_interface

namespace rosidl_generator_traits
{

[[deprecated("use advanced_user_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const advanced_user_interface::msg::Point2 & msg,
  std::ostream & out, size_t indentation = 0)
{
  advanced_user_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use advanced_user_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const advanced_user_interface::msg::Point2 & msg)
{
  return advanced_user_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<advanced_user_interface::msg::Point2>()
{
  return "advanced_user_interface::msg::Point2";
}

template<>
inline const char * name<advanced_user_interface::msg::Point2>()
{
  return "advanced_user_interface/msg/Point2";
}

template<>
struct has_fixed_size<advanced_user_interface::msg::Point2>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<advanced_user_interface::msg::Point2>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<advanced_user_interface::msg::Point2>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ADVANCED_USER_INTERFACE__MSG__DETAIL__POINT2__TRAITS_HPP_
