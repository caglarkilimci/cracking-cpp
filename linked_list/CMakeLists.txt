cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(linked_list_tests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the linked_list library
add_library(linked_list STATIC linked_list.c)

# Add the executable for the test
add_executable(test_linked_list test_linked_list.c)

# Link the linked_list library to the test executable
target_link_libraries(test_linked_list PRIVATE linked_list)

# Enable testing
enable_testing()

# Add a test
add_test(NAME linked_list_test COMMAND test_linked_list)
