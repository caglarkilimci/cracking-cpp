cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(twoSum_tests VERSION 1.0)

# Add the twoSum library
add_library(twoSum STATIC twoSum.cpp)

# Add the executable for the test
add_executable(test_twoSum test_twoSum.cpp)

# Link the twoSum library to the test executable
target_link_libraries(test_twoSum PRIVATE twoSum)

# Enable testing
enable_testing()

# Add a test
add_test(NAME twoSum_test COMMAND test_twoSum)
