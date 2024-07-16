cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(memory_layout_tests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the memory_layout library
add_library(memory_layout STATIC memory_layout.c)

# Add the executable for the test
add_executable(test_memory_layout test_memory_layout.c)

# Link the memory_layout library to the test executable
target_link_libraries(test_memory_layout PRIVATE memory_layout)

# Enable testing
enable_testing()

# Add a test
add_test(NAME memory_layout_test COMMAND test_memory_layout)
