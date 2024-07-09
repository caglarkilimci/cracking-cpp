cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(sample_c_tests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the sample_c library
add_library(sample_c STATIC sample_c.c)

# Add the executable for the test
add_executable(test_sample_c test_sample_c.c)

# Link the sample_c library to the test executable
target_link_libraries(test_sample_c PRIVATE sample_c)

# Enable testing
enable_testing()

# Add a test
add_test(NAME sample_c_test COMMAND test_sample_c)
