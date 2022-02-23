add_executable(${PROJECT_NAME}_test main_test.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME})