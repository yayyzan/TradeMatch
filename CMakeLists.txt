cmake_minimum_required(VERSION 3.10)  # Specify the minimum CMake version
project(TradeMatch)                     # Define the project name

set(CMAKE_CXX_STANDARD 11)              # Set the C++ standard to C++11

# Define the source files
set(SOURCES
    src/engine/Exchange.cpp
    src/engine/OrderBook.cpp
    src/engine/Order.cpp
    src/engine/Trade.cpp
    src/client/ClientInterface.cpp
    src/engine/Logger.cpp
    src/main.cpp
)

# Create the executable
add_executable(TradeMatch ${SOURCES})

# Optionally, you can include directories if needed
# For example, if you have a "include" directory for header files, uncomment below:
# include_directories(include)

# If you need to link against any libraries, you can do so here
# target_link_libraries(TradeMatch <your_library_here>)
