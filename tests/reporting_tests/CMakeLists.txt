add_executable( tests
  eventfilesource.ut.cpp
  eventinmemorystore.ut.cpp
  eventprocessor.ut.cpp
  eventquestionablefilter.ut.cpp
  eventstoreprocessor.ut.cpp
  eventsubject.ut.cpp
)

target_include_directories( tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

target_link_libraries( tests
  reporting
  gtest
  gtest_main
  gmock
)

add_test( NAME eventfilesource COMMAND tests --gtest_filter=eventfilesource* )
add_test( NAME eventinmemorystore COMMAND tests --gtest_filter=eventinmemorystore* )
add_test( NAME eventprocessor COMMAND tests --gtest_filter=eventprocessor* )
add_test( NAME eventquestionablefilter COMMAND tests --gtest_filter=eventquestionablefilter* )
add_test( NAME eventstoreprocessor COMMAND tests --gtest_filter=eventstoreprocessor* )
add_test( NAME eventsubject COMMAND tests --gtest_filter=eventsubject* )

