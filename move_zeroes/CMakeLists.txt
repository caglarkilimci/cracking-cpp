cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(move_zeroes_tests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the move_zeroes library
add_library(move_zeroes STATIC move_zeroes.cpp)

# Add the executable for the test
add_executable(test_move_zeroes test_move_zeroes.cpp)

# Link the move_zeroes library to the test executable
target_link_libraries(test_move_zeroes PRIVATE move_zeroes)

# Enable testing
enable_testing()

# Add a test
add_test(NAME move_zeroes_test COMMAND test_move_zeroes)
