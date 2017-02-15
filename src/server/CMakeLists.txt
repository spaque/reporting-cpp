file( GLOB REPORTING_SERVER_SOURCE_FILES "*.cpp" )
add_executable( server $(REPORTING_SERVER_SOURCE_FILES) )

target_link_libraries( server 
LINK_PUBLIC reporting
${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_SYSTEM_LIBRARY}
)
