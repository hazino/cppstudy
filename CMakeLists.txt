cmake_minimum_required(VERSION 3.29)
project(cppstudy VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)
include_directories(${JSONCPP_INCLUDE_DIRS})

include_directories(
    message
)
add_executable(cppstudy
    src/main.cpp)

target_link_libraries(cppstudy ${JSONCPP_LIBRARIES_FULL_PATH})
