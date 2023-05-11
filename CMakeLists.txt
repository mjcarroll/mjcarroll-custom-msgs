cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

#============================================================================
# Initialize the project
#============================================================================
project(mjcarroll-custom-msgs VERSION 1.0.0)

#============================================================================
# Find gz-cmake
#============================================================================
find_package(gz-cmake3 REQUIRED)

find_package(gz-msgs10 REQUIRED)

# Get the gz-msgs installed messages and generate a library from them
get_installed_messages(
  MESSAGES_PATH_VARIABLE MSGS_PATH
  MESSAGES_PROTOS_VARIABLE MSGS_PROTOS)
generate_messages(
  TARGET gz_msgs_gen
  PROTO_PACKAGE "gz.msgs"
  MSGS_PATH ${MSGS_PATH}
  MSGS_PROTOS ${MSGS_PROTOS})

# Example of custom messages that depend on gz.msgs
set(MSGS_PROTOS
    ${CMAKE_CURRENT_SOURCE_DIR}/proto/mjcarroll/foo/my_bytes.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/proto/mjcarroll/foo/depends.proto)
generate_messages(
  TARGET mjcarroll_msgs_gen
  PROTO_PACKAGE "mjcarroll.foo"
  MSGS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/proto
  MSGS_PROTOS ${MSGS_PROTOS}
  DEPENDENCIES gz_msgs_gen
)

# Example of custom messages that depend on mjcarroll.foo
set(MSGS2_PROTOS
    ${CMAKE_CURRENT_SOURCE_DIR}/proto/mjcarroll2/foo/depends2.proto)
generate_messages(
  TARGET mjcarroll2_msgs_gen
  PROTO_PACKAGE "mjcarroll2.foo"
  MSGS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/proto
  MSGS_PROTOS ${MSGS2_PROTOS}
  DEPENDENCIES mjcarroll_msgs_gen
)

add_executable(${PROJECT_NAME} foo_main.cc)

target_link_libraries(${PROJECT_NAME} PUBLIC gz-msgs10::gz-msgs10)

# This is one option, which uses whole-archive linking to get all the messages available
target_link_messages(TARGET ${PROJECT_NAME} PUBLIC MSG_TARGETS mjcarroll_msgs_gen mjcarroll2_msgs_gen gz_msgs_gen)

install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)
