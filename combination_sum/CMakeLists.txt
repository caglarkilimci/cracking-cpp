cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(combination_sum_tests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the combination_sum library
add_library(combination_sum STATIC combination_sum.c)

# Add the executable for the test
add_executable(test_combination_sum test_combination_sum.c)

# Link the combination_sum library to the test executable
target_link_libraries(test_combination_sum PRIVATE combination_sum)

# Enable testing
enable_testing()

# Add a test
add_test(NAME combination_sum_test COMMAND test_combination_sum)
