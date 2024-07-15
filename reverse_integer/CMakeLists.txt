cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(reverse_integer_tests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the reverse_integer library
add_library(reverse_integer STATIC reverse_integer.c)

# Add the executable for the test
add_executable(test_reverse_integer test_reverse_integer.c)

# Link the reverse_integer library to the test executable
target_link_libraries(test_reverse_integer PRIVATE reverse_integer)

# Enable testing
enable_testing()

# Add a test
add_test(NAME reverse_integer_test COMMAND test_reverse_integer)
