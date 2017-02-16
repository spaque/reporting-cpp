add_executable( server server.cpp )

target_link_libraries( server
LINK_PUBLIC reporting
${Boost_LIBRARIES}
Threads::Threads
)

