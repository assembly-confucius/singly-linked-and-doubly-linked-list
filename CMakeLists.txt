cmake_minimum_required(VERSION 3.30)

project(lists)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

FetchContent_MakeAvailable(googletest)

add_library(OneList INTERFACE
	library.h
)

target_include_directories(OneList INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(DoublyList INTERFACE
	DoubleList.h
)

target_include_directories(DoublyList INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()
add_subdirectory(tests)
