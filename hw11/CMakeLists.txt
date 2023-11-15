cmake_minimum_required( VERSION 3.12 ) 
project( nicolesprogram VERSION 1.0 )

add_executable( nicolesez exercises.cpp )
install( TARGETS nicolesez DESTINATION . )