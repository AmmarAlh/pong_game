// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from advanced_user_interface:msg/Point2.idl
// generated code does not contain a copyright notice

#ifndef ADVANCED_USER_INTERFACE__MSG__DETAIL__POINT2__STRUCT_HPP_
#define ADVANCED_USER_INTERFACE__MSG__DETAIL__POINT2__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__advanced_user_interface__msg__Point2 __attribute__((deprecated))
#else
# define DEPRECATED__advanced_user_interface__msg__Point2 __declspec(deprecated)
#endif

namespace advanced_user_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Point2_
{
  using Type = Point2_<ContainerAllocator>;

  explicit Point2_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  explicit Point2_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    advanced_user_interface::msg::Point2_<ContainerAllocator> *;
  using ConstRawPtr =
    const advanced_user_interface::msg::Point2_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<advanced_user_interface::msg::Point2_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<advanced_user_interface::msg::Point2_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      advanced_user_interface::msg::Point2_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<advanced_user_interface::msg::Point2_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      advanced_user_interface::msg::Point2_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<advanced_user_interface::msg::Point2_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<advanced_user_interface::msg::Point2_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<advanced_user_interface::msg::Point2_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__advanced_user_interface__msg__Point2
    std::shared_ptr<advanced_user_interface::msg::Point2_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__advanced_user_interface__msg__Point2
    std::shared_ptr<advanced_user_interface::msg::Point2_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Point2_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const Point2_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Point2_

// alias to use template instance with default allocator
using Point2 =
  advanced_user_interface::msg::Point2_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace advanced_user_interface

#endif  // ADVANCED_USER_INTERFACE__MSG__DETAIL__POINT2__STRUCT_HPP_
