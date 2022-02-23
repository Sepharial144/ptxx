
set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)

add_library(
	${PROJECT_NAME}
	ptxx.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRNET_SOURCE_DIR}")