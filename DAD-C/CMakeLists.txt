cmake_minimum_required(VERSION 3.29)

project(main)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(SRC "src")

# disable warnings
add_definitions(-w)

find_package(json-c CONFIG)

include_directories(include)

include_directories()

add_executable(
    ${SRC}/main.c
    ${SRC}/list/list.c
    )

target_link_libraries( -lcurl -lpthread -lxml2 -ljson-c -lpcap)


