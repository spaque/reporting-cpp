add_executable( client client.cpp )

target_link_libraries( client
LINK_PUBLIC reporting
${Boost_LIBRARIES}
Threads::Threads
)

