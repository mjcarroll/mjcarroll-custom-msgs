# Get the gz-msgs installed messages and generate a library from them
gz_msgs_get_installed_messages(
  MESSAGES_PATH_VARIABLE MSGS_PATH
  MESSAGES_PROTOS_VARIABLE MSGS_PROTOS)

gz_msgs_generate_messages(
  TARGET lib1_msgs_gen
  PREFIX_PROTO_PACKAGE "lib1"
  PROTO_PACKAGE "gz.msgs"
  MSGS_PATH ${MSGS_PATH}
  MSGS_PROTOS ${MSGS_PROTOS})

add_library(lib1 SHARED lib1.cc)
target_link_libraries(lib1 gz-msgs10::gz-msgs10)
target_link_messages(TARGET lib1 MSG_TARGETS lib1_msgs_gen)

install(TARGETS lib1
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)
