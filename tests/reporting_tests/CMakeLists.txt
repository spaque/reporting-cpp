add_executable( tests
  eventinmemorystore.ut.cpp
  eventprocessor.ut.cpp
  eventquestionablefilter.ut.cpp
  eventstoreprocessor.ut.cpp
  eventsubject.ut.cpp
)

target_include_directories( tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

target_link_libraries( tests
LINK_PUBLIC reporting
#GTest::GTest
#GTest::Main
)

add_test( eventinmemorystore eventinmemorystore_test )
add_test( eventprocessor eventprocessor_test )
add_test( eventquestionablefilter eventquestionablefilter_test )
add_test( eventstoreprocessor eventstoreprocessor_test )
add_test( eventsubject eventsubject_test )

