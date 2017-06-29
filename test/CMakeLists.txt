cmake_minimum_required(VERSION 3.5)
project(OpalTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -Wextra -pedantic -std=c++1z")
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/debug)
set(CMAKE_RUNTIME_OUTPUT_DURECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/release)


set(SOURCE_FILES
    main.cc
    scene.cc
)

add_executable(scene ${SOURCE_FILES})
include_directories("../../Opal-Engine/src/")
target_link_libraries(scene ~/Programming/Opal/Opal-Engine/libopal.so)
