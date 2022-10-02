cmake_minimum_required( VERSION 2.8 )
project( hello )

set( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( hello src/hello.cc )
