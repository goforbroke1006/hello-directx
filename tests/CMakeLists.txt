project(hello-directx-test)

enable_testing()

add_executable(${PROJECT_NAME} ./main.cpp)
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

add_test(runUnitTests ${PROJECT_NAME})