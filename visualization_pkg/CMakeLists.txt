cmake_minimum_required(VERSION 3.8)
project(visualization_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(SDL2 REQUIRED)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
set(SDL2_TTF_LIBRARIES SDL2_ttf) # Officially this should be done with find_package, but due to a bug that does not work


add_executable(visualization_node src/visualization_node.cpp src/Pong_field.cpp src/SDL2_UI.cpp)
 ament_target_dependencies(visualization_node rclcpp std_msgs)

# Include the SDL libraries (as found above) for this executable
target_link_directories(visualization_node PUBLIC ${SDL2_LINK_DIRS})
target_include_directories(visualization_node PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(visualization_node ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})

target_include_directories(visualization_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(visualization_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

install(TARGETS 
  visualization_node 
  DESTINATION lib/${PROJECT_NAME})

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
