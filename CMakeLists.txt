cmake_minimum_required(VERSION 3.22.1)
project(patd_lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_INCLUDES
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/core
        ${PROJECT_SOURCE_DIR}/include/ArraySequence
        ${PROJECT_SOURCE_DIR}/include/ArraySequence/Mutable
        ${PROJECT_SOURCE_DIR}/include/ArraySequence/Immutable
        ${PROJECT_SOURCE_DIR}/include/ListSequence
        ${PROJECT_SOURCE_DIR}/include/ListSequence/Mutable
        ${PROJECT_SOURCE_DIR}/include/ListSequence/Immutable
        ${PROJECT_SOURCE_DIR}/include/SequenceInterface
)

include_directories(${PROJECT_INCLUDES})

add_executable(main src/main.cpp)
target_include_directories(main PRIVATE ${PROJECT_INCLUDES})

add_executable(test src/test.cpp)
target_include_directories(test PRIVATE ${PROJECT_INCLUDES})
