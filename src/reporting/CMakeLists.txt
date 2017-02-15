file( GLOB REPORTING_SOURCE_FILES "*.cpp" )
add_library( reporting $(REPORTING_SOURCE_FILES) )

target_link_libraries( reporting ${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_SYSTEM_LIBRARY} )
target_include_directories( reporting PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
