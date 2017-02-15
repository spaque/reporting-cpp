file( GLOB REPORTING_TESTS_SOURCE_FILES "*.cpp" )
add_executable( tests $(REPORTING_SOURCE_FILES) )

target_link_libraries( tests
LINK_PUBLIC reporting
GTest::GTest
GTest::Main
)

add_test( eventinmemorystore eventinmemorystore_test )
add_test( eventprocessor eventprocessor_test )
add_test( eventquestionablefilter eventquestionablefilter_test )
add_test( eventstoreprocessor eventstoreprocessor_test )
add_test( eventsubject eventsubject_test )
