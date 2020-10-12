cmake_minimum_required(VERSION 3.0.2)
project(ros_tutorials_action)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  std_msgs
  actionlib_msgs
  actionlib
  roscpp
)

find_package(Boost REQUIRED COMPONENTS system)

add_action_files(FILES Fibonacci.action)
generate_messages(DEPENDENCIES actionlib_msgs std_msgs)

catkin_package(
  LIBRARIES ros_tutorial_action
  CATKIN_DEPENDS std_msgs actionlib_msgs actionlib roscpp
  DEPENDS Boost
)

include_directories(${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

add_executable(action_server src/action_server.cpp)
add_dependencies(action_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGET})
target_link_libraries(action_server ${catkin_LIBRARIES})

add_executable(action_client src/action_client.cpp)
add_dependencies(action_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGET})
target_link_libraries(action_client ${catkin_LIBRARIES})
