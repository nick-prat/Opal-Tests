cmake_minimum_required(VERSION 3.5)
project(OpalTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -Wextra -pedantic -std=c++17 -fcolor-diagnostics")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/debug)
set(CMAKE_RUNTIME_OUTPUT_DURECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/release)

set(SOURCE_FILES
    main.cc
    scene.cc
    systems.cc
)

find_package(Lua51 REQUIRED)
add_executable(scene.out ${SOURCE_FILES})
include_directories("../../Opal-Engine/include/" ${LUA_INCLUDE_DIR})
target_link_libraries(scene.out -lopal -llua5.1)
# target_link_libraries(scene.out "../../Opal-Engine/build/libopal.so" -llua5.1)
