add_executable( tests
  eventinmemorystore.ut.cpp
  eventprocessor.ut.cpp
  eventquestionablefilter.ut.cpp
  eventstoreprocessor.ut.cpp
  eventsubject.ut.cpp
)

target_include_directories( tests SYSTEM PRIVATE ${GTEST_DIR}/googletest/include ${GTEST_DIR}/googlemock/include)
target_include_directories( tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

target_link_libraries( tests
  reporting
  gtest
  gtest_main
  gmock
)

add_test( eventinmemorystore eventinmemorystore_test )
add_test( eventprocessor eventprocessor_test )
add_test( eventquestionablefilter eventquestionablefilter_test )
add_test( eventstoreprocessor eventstoreprocessor_test )
add_test( eventsubject eventsubject_test )

