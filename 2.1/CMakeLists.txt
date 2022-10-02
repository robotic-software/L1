cmake_minimum_required( VERSION 2.8 )
project( boost1 )


find_package(Boost COMPONENTS system REQUIRED)

set( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( es2.1 src/2.1.cpp )
target_link_libraries( es2.1 boost_system boost_thread)
