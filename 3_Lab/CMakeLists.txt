cmake_minimum_required(VERSION 3.2)

project(lab3)
find_package(GTest REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")
enable_testing()

set(LIBS ./src/Figures/Quadangle.cpp ./src/Figures/Rectangle.cpp ./src/Figures/Square ./src/Figures/Trapezoid ./src/Vector.cpp)

set(SOURCE_OUT ./src/main.cpp ${LIBS})
add_executable(${PROJECT_NAME} ${SOURCE_OUT})


set(TEST_NAME tests)
add_executable(${TEST_NAME} ./src/tests/tests.cpp ${LIBS})
target_link_libraries(${TEST_NAME} ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME BASIC COMMAND tests)
