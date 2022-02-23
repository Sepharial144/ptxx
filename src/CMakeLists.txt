add_library(
	${PROJECT_NAME}
	ptxx.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRNET_SOURCE_DIR}")