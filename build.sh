#!/bin/bash

# Create a build directory if it doesn't exist
BUILD_DIR="build"
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

# Navigate to the build directory
cd "$BUILD_DIR"

# Run CMake to configure the project
cmake ..

# Build the project
cmake --build .

# Check if the build was successful
if [ $? -eq 0 ]; then
    echo "Build successful. Running the executable..."
    # Run the executable
    ./TradeMatch
else
    echo "Build failed. Please check the errors."
fi

