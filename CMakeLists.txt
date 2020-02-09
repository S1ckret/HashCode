cmake_minimum_required(VERSION 3.12)
project(HashCode VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)

file(GLOB
         CPPS "src/*.cpp")

include_directories(${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${CPPS})