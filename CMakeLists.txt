cmake_minimum_required( VERSION 3.1.0 )
project( report CXX )

set( CMAKE_CXX_STANDARD 11 )

message( STATUS "CMAKE_C_COMPILER: " ${CMAKE_C_COMPILER} )
message( STATUS "CMAKE_CXX_COMPILER: " ${CMAKE_CXX_COMPILER} )
message( STATUS "CMAKE_CXX_COMPILER_VERSION: " ${CMAKE_CXX_COMPILER_VERSION} )
message( STATUS "CMAKE_COMPILER_IS_GNUCC: " ${CMAKE_COMPILER_IS_GNUCC} )
message( STATUS "CMAKE_COMPILER_IS_GNUCXX : " ${CMAKE_COMPILER_IS_GNUCXX} )
message( STATUS "CMAKE_C_FLAGS: " ${CMAKE_C_FLAGS} )
message( STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS} )

if( CMAKE_CXX_COMPILER_ID STREQUAL "GNU" )
  if( CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.8 )
    message( FATAL_ERROR "GCC version must be at least 4.8!" )
  endif()
elseif( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" )
  if( CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.3 )
    message( FATAL_ERROR "Clang version must be at least 3.3!" )
  endif()
elseif( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )
  if( CMAKE_CXX_COMPILER_VERSION VERSION_LESS 12.0 )
    message( FATAL_ERROR "MSVC version must be at least 12.0!" )
  endif()
endif()

set( Boost_USE_STATIC_LIBS ON )
set( Boost_USE_MULTITHREADED ON )
set( Boost_USE_STATIC_RUNTIME ON )
find_package( Boost REQUIRED COMPONENTS system )
include_directories( ${Boost_INCLUDE_DIRS} )

find_package( Threads )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory( "src/reporting" )
add_subdirectory( "src/client" )
add_subdirectory( "src/server" )

enable_testing()
#find_package( GTest REQUIRED )
add_subdirectory( "tests/reporting_tests" )

