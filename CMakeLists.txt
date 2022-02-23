cmake_minimum_required(VERSION 3.2)

project(
	ptxx 
	VERSION 0.12 
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)

enable_testing()

add_subdirectory(src)

if(testing_enabled)
    add_subdirectory(tests)
endif()