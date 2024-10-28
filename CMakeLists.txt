cmake_minimum_required(VERSION 3.10)
project(OrderMatchingEngine)

set(CMAKE_CXX_STANDARD 17)

# Define the executable and its source files
add_executable(OrderMatchingEngine src/main.cpp)

# Include directories
target_include_directories(OrderMatchingEngine PRIVATE src/engine)