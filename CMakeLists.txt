cmake_minimum_required(VERSION 2.8.3)
project(hello_world)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES hello_world
  CATKIN_DEPENDS roscpp std_msgs
 ## DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(node1 src/node1.cpp)
##add_dependencies(node1 ${PROJECT_NAME}_generate_messages_cpp)
target_link_libraries(node1 ${catkin_LIBRARIES})

add_executable(node2 src/node2.cpp)
##add_dependencies(node2 ${PROJECT_NAME}_generate_messages_cpp)
target_link_libraries(node2 ${catkin_LIBRARIES})

add_executable(node3 src/node3.cpp)
##add_dependencies(node3 ${PROJECT_NAME}_generate_messages_cpp)
target_link_libraries(node3 ${catkin_LIBRARIES})

add_executable(node4 src/node4.cpp)
##add_dependencies(node4 ${PROJECT_NAME}_generate_messages_cpp)
target_link_libraries(node4 ${catkin_LIBRARIES})

add_executable(node5 src/node5.cpp)
##add_dependencies(node5 ${PROJECT_NAME}_generate_messages_cpp)
target_link_libraries(node5 ${catkin_LIBRARIES})