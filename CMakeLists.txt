cmake_minimum_required(VERSION 3.10)

# Set project name
project(DilatedConvolution)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include header files
include_directories(include)

# Add source files
set(SOURCES
    src/main.cpp
    src/random_generator.cpp
    src/convolution.cpp
)

# Create executable
add_executable(dilated_convolution ${SOURCES})

