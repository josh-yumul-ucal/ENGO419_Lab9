
cmake_minimum_required(VERSION 3.20)

project(ENGO419_Lab9 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Eigen 5.0.0
FetchContent_Declare(
    eigen
    URL https://gitlab.com/libeigen/eigen/-/archive/5.0.0/eigen-5.0.0.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(eigen)

# Executable
add_executable(ENGO419_Lab9
    main.cpp
    functions.cpp
    functions.h
)

target_link_libraries(ENGO419_Lab9 PRIVATE
    Eigen3::Eigen
)
