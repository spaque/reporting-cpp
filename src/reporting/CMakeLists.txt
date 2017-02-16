add_library( reporting
  eventfiledump.cpp
  eventfilesource.cpp
  eventinmemorystore.cpp
  eventnetworksource.cpp
  eventnetworktarget.cpp
  eventprinter.cpp
  eventprocessor.cpp
  eventquestionablefilter.cpp
  eventstoreprocessor.cpp
  eventsubject.cpp
)

target_link_libraries( reporting ${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_SYSTEM_LIBRARY} )
target_include_directories( reporting PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
