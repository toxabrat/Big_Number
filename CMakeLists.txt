cmake_minimum_required(VERSION 3.16)
project(Big_Number)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-O2 -Wall)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/BigNumber.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/BigNumber.h
    ${CMAKE_CURRENT_SOURCE_DIR}/BigNumberTest.cpp
)

add_library(BigNumber STATIC ${SOURCES})

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(BigNumber Boost::unit_test_framework)

add_executable(main main.cpp)
target_link_libraries(main BigNumber)

enable_testing()
add_test(NAME BigNumberTest COMMAND BigNumberTest)