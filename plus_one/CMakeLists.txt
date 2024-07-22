cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(plus_one_tests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the plus_one library
add_library(plus_one STATIC plus_one.c)

# Add the executable for the test
add_executable(test_plus_one test_plus_one.c)

# Link the plus_one library to the test executable
target_link_libraries(test_plus_one PRIVATE plus_one)

# Enable testing
enable_testing()

# Add a test
add_test(NAME plus_one_test COMMAND test_plus_one)
