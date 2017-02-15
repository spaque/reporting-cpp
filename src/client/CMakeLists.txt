file( GLOB REPORTING_CLIENT_SOURCE_FILES "*.cpp" )
add_executable( client $(REPORTING_CLIENT_SOURCE_FILES) )

target_link_libraries( client
LINK_PUBLIC reporting
${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_SYSTEM_LIBRARY}
)
