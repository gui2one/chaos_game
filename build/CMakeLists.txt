cmake_minimum_required(VERSION 2.8)
#set(CMAKE_CXX_FLAGS -std=c++1y)
project(chaos_game)

set(CMAKE_CXX_FLAGS -std=c++11)

add_executable(chaos_game
	../src/main.cpp
)
target_link_libraries(chaos_game -lGL)
target_link_libraries(chaos_game -lglfw)
target_link_libraries(chaos_game -lGLEW)
target_link_libraries(chaos_game -lfreeimageplus)
