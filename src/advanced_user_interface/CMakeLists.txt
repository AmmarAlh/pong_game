cmake_minimum_required(VERSION 3.8)
project(advanced_user_interface)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


include_directories(include)

# Find dependencies
set(DEPENDENCIES
  "ament_cmake"
  "rclcpp"
  "rclcpp_components"
  "sensor_msgs"
  "std_msgs"
  "OpenCV"
  "cv_bridge"
  "image_transport"
  "rosidl_default_generators"
)

# Find all packages
foreach(dep IN LISTS DEPENDENCIES)
  find_package(${dep} REQUIRED)
endforeach()

# Function to add executables and their dependencies
function(custom_executable target)
  add_executable(${target} src/${target}_node.cpp  src/${target}.cpp)
  
  # Add ament dependencies
  foreach(dep IN LISTS DEPENDENCIES)
    ament_target_dependencies(${target} ${dep})
  endforeach()
  
  rosidl_get_typesupport_target(${target}_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp") 
  target_link_libraries(${target} ${${target}_typesupport_target})

  install(TARGETS ${target}
  DESTINATION lib/${PROJECT_NAME})

  target_include_directories(${target} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

  target_compile_features(${target} PUBLIC cxx_std_14)  # Require C99 and C++17
endfunction()

ament_export_dependencies(rosidl_default_runtime)
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Point2.msg"
  DEPENDENCIES builtin_interfaces
)


custom_executable(light_position_detection)





if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
