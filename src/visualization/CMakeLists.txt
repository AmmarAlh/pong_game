cmake_minimum_required(VERSION 3.8)
project(visualization)

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
)
find_package(SDL2 REQUIRED)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
set(SDL2_TTF_LIBRARIES SDL2_ttf) 


# Find all packages
foreach(dep IN LISTS DEPENDENCIES)
  find_package(${dep} REQUIRED)
endforeach()

# Function to add executables and their dependencies
function(custom_executable target)

  file(GLOB_RECURSE sources "src/*.cpp")

  add_executable(${target} src/${target}_node.cpp  ${sources})
  # Add ament dependencies
  foreach(dep IN LISTS DEPENDENCIES)
    ament_target_dependencies(${target} ${dep})
  endforeach()
 

  install(TARGETS ${target}
  DESTINATION lib/${PROJECT_NAME})

  target_include_directories(${target} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include> ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})

  target_link_libraries(${target} ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})

  target_compile_features(${target} PUBLIC cxx_std_14)  # Require C99 and C++17
endfunction()



custom_executable(game_render)





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
