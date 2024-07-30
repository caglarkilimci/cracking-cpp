cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(merge_sorted_array_tests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the merge_sorted_array library
add_library(merge_sorted_array STATIC merge_sorted_array.cpp)

# Add the executable for the test
add_executable(test_merge_sorted_array test_merge_sorted_array.cpp)

# Link the merge_sorted_array library to the test executable
target_link_libraries(test_merge_sorted_array PRIVATE merge_sorted_array)

# Enable testing
enable_testing()

# Add a test
add_test(NAME merge_sorted_array_test COMMAND test_merge_sorted_array)
