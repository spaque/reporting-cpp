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
message( STATUS "CMAKE_CXX_FLAGS_RELEASE: " ${CMAKE_CXX_FLAGS_RELEASE} )
message( STATUS "CMAKE_CXX_FLAGS_DEBUG: " ${CMAKE_CXX_FLAGS_DEBUG} )

if( CMAKE_CXX_COMPILER_ID STREQUAL "GNU" )
  if( CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.9 )
    message( FATAL_ERROR "GCC version must be at least 4.9!" )
  endif()
elseif( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" )
  if( CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.3 )
    message( FATAL_ERROR "Clang version must be at least 3.3!" )
  endif()
elseif( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )
  if( CMAKE_CXX_COMPILER_VERSION VERSION_LESS 17.0 )
    message( FATAL_ERROR "MSVC version must be at least 17.0!" )
  endif()
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# WARNING This needs to happen before boost
add_subdirectory( "thirdparty/gtest-1.8.0" )
include_directories(
  ${gmock_SOURCE_DIR}/include
  ${gmock_SOURCE_DIR}
  ${gtest_SOURCE_DIR}/include
  ${gtest_SOURCE_DIR}
)

find_package( Boost REQUIRED COMPONENTS system )
include_directories( ${Boost_INCLUDE_DIRS} )
if( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )
  link_directories( ${Boost_LIBRARY_DIRS} )
endif()

message( STATUS "Boost_VERSION: " ${Boost_VERSION} )

find_package( Threads )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory( "src/reporting" )
add_subdirectory( "src/client" )
add_subdirectory( "src/server" )

enable_testing()
add_subdirectory( "tests/reporting_tests" )

