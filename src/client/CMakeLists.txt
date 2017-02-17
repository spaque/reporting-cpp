add_executable( client client.cpp )

target_link_libraries( client
  LINK_PUBLIC reporting
  ${Boost_LIBRARIES}
  Threads::Threads
)

add_custom_command(
  TARGET client POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  ${CMAKE_CURRENT_SOURCE_DIR}/sample.log
  $<TARGET_FILE_DIR:client>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  ${CMAKE_CURRENT_SOURCE_DIR}/config.json
  $<TARGET_FILE_DIR:client>
)
