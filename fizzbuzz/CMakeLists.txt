cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(FizzBuzzTests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the FizzBuzz library
add_library(fizzbuzz STATIC fizzbuzz.c)

# Add the executable for the test
add_executable(test_fizzbuzz test_fizzbuzz.c)

# Link the FizzBuzz library to the test executable
target_link_libraries(test_fizzbuzz PRIVATE fizzbuzz)

# Enable testing
enable_testing()

# Add a test
add_test(NAME FizzbuzzTest COMMAND test_fizzbuzz)
