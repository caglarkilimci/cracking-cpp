cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(sample_cpp_tests VERSION 1.0)

# Add the sample_cpp library
add_library(sample_cpp STATIC sample_cpp.cpp)

# Add the executable for the test
add_executable(test_sample_cpp test_sample_cpp.cpp)

# Link the sample_cpp library to the test executable
target_link_libraries(test_sample_cpp PRIVATE sample_cpp)

# Enable testing
enable_testing()

# Add a test
add_test(NAME sample_cpp_test COMMAND test_sample_cpp)
