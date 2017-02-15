add_executable( client client.cpp )

target_link_libraries( client
LINK_PUBLIC reporting
${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_SYSTEM_LIBRARY}
Threads::Threads
)

