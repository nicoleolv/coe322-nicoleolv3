cmake_minimum_required( VERSION 3.17 )
project( tsp VERSION 1.0 )

set(CMAKE_CXX_STANDARD 17)

add_executable( tsmp tsmp.cpp )
install( TARGETS tsp DESTINATION . )