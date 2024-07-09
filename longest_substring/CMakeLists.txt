cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(longest_substring_tests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the longest_substring library
add_library(longest_substring STATIC longest_substring.c)

# Add the executable for the test
add_executable(test_longest_substring test_longest_substring.c)

# Link the longest_substring library to the test executable
target_link_libraries(test_longest_substring PRIVATE longest_substring)

# Enable testing
enable_testing()

# Add a test
add_test(NAME longest_substring_test COMMAND test_longest_substring)
