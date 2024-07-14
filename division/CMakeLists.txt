cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(division_tests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the division library
add_library(division STATIC division.c)

# Add the executable for the test
add_executable(test_division test_division.c)

# Link the division library to the test executable
target_link_libraries(test_division PRIVATE division)

# Enable testing
enable_testing()

# Add a test
add_test(NAME division_test COMMAND test_division)
