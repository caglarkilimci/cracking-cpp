cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(reverse_string_tests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the reverse_string library
add_library(reverse_string STATIC reverse_string.c)

# Add the executable for the test
add_executable(test_reverse_string test_reverse_string.c)

# Link the reverse_string library to the test executable
target_link_libraries(test_reverse_string PRIVATE reverse_string)

# Enable testing
enable_testing()

# Add a test
add_test(NAME reverse_string_test COMMAND test_reverse_string)
