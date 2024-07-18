cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(single_number_tests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the single_number library
add_library(single_number STATIC single_number.c)

# Add the executable for the test
add_executable(test_single_number test_single_number.c)

# Link the single_number library to the test executable
target_link_libraries(test_single_number PRIVATE single_number)

# Enable testing
enable_testing()

# Add a test
add_test(NAME single_number_test COMMAND test_single_number)
