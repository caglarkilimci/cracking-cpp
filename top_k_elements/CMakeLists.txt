cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(top_k_elements_tests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the top_k_elements library
add_library(top_k_elements STATIC top_k_elements.c)

# Add the executable for the test
add_executable(test_top_k_elements test_top_k_elements.c)

# Link the top_k_elements library to the test executable
target_link_libraries(test_top_k_elements PRIVATE top_k_elements)

# Enable testing
enable_testing()

# Add a test
add_test(NAME top_k_elements_test COMMAND test_top_k_elements)
