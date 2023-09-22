cmake_minimum_required(VERSION 3.27)
project(lab1)

set(CMAKE_CXX_STANDART 17)

enable_testing()
find_package(GTest REQUIRED)

add_executable(lab1 src/main.cpp)

add_executable(unit_tests tests/test.cpp)
target_link_libraries(unit_tests GTest::gtest_main)

add_test(
    NAME unit_tests
    COMMAND unit_tests
)
