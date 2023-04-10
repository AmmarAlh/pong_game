// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from advanced_user_interface:msg/Point2.idl
// generated code does not contain a copyright notice

#ifndef ADVANCED_USER_INTERFACE__MSG__DETAIL__POINT2__BUILDER_HPP_
#define ADVANCED_USER_INTERFACE__MSG__DETAIL__POINT2__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "advanced_user_interface/msg/detail/point2__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace advanced_user_interface
{

namespace msg
{

namespace builder
{

class Init_Point2_y
{
public:
  explicit Init_Point2_y(::advanced_user_interface::msg::Point2 & msg)
  : msg_(msg)
  {}
  ::advanced_user_interface::msg::Point2 y(::advanced_user_interface::msg::Point2::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::advanced_user_interface::msg::Point2 msg_;
};

class Init_Point2_x
{
public:
  Init_Point2_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Point2_y x(::advanced_user_interface::msg::Point2::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Point2_y(msg_);
  }

private:
  ::advanced_user_interface::msg::Point2 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::advanced_user_interface::msg::Point2>()
{
  return advanced_user_interface::msg::builder::Init_Point2_x();
}

}  // namespace advanced_user_interface

#endif  // ADVANCED_USER_INTERFACE__MSG__DETAIL__POINT2__BUILDER_HPP_
