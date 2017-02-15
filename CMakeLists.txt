cmake_minimum_required( VERSION 3.0.0 )
project( report )

#include_directories ("${PROJECT_SOURCE_DIR}/src/reporting")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package( Boost REQUIRED COMPONENTS system )
include_directories( ${Boost_INCLUDE_DIRS} )

add_subdirectory( "src/reporting" )
add_subdirectory( "src/client" )
add_subdirectory( "src/server" )

enable_testing()
find_package( GTest REQUIRED )
add_subdirectory( "tests/reporting_tests" )
