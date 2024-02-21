cmake_minimum_required(VERSION 3.16)
project(Big_Number)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_compile_options(-O2 -Wall)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/BigNumber.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/BigNumber.h
)

add_library(BigNumber SHARED ${SOURCES})

add_executable(main main.cpp)
target_link_libraries(main BigNumber)

add_subdirectory(tests)