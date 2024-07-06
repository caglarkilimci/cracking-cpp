cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(FibonacciTests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the Fibonacci library
add_library(fibonacci STATIC fibonacci.c)

# Add the executable for the test
add_executable(test_fibonacci test_fibonacci.c)

# Link the Fibonacci library to the test executable
target_link_libraries(test_fibonacci PRIVATE fibonacci)

# Enable testing
enable_testing()

# Add a test
add_test(NAME FibonacciTest COMMAND test_fibonacci)
