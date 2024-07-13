cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(rotate_array_tests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the rotate_array library
add_library(rotate_array STATIC rotate_array.c)

# Add the executable for the test
add_executable(test_rotate_array test_rotate_array.c)

# Link the rotate_array library to the test executable
target_link_libraries(test_rotate_array PRIVATE rotate_array)

# Enable testing
enable_testing()

# Add a test
add_test(NAME rotate_array_test COMMAND test_rotate_array)
