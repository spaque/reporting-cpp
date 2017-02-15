add_executable( server server.cpp )

target_link_libraries( server
LINK_PUBLIC reporting
${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_SYSTEM_LIBRARY}
)
