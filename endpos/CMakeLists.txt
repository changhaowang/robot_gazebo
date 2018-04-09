cmake_minimum_required(VERSION 2.8.3)
project(endpos)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++0x")
## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  cmake_modules
  interactive_markers
  moveit_core
  moveit_ros_perception
  moveit_ros_planning_interface
  pluginlib
  roscpp
  rospy
  std_msgs
)

find_package(Boost REQUIRED COMPONENTS system)
catkin_package(
)

include_directories(
include
  ${catkin_INCLUDE_DIRS}
)

add_executable(test_custom_node src/pos.cpp)
add_dependencies(test_custom_node endpos_generate_messages_cpp)
target_link_libraries(test_custom_node
   ${catkin_LIBRARIES}
 )
