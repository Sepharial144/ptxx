cmake_minimum_required(VERSION 3.2)

project(
	ptxx 
	VERSION 0.12 
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED True)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(${PROJECT_NAME} main.cpp)