cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(palindrome_tests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the palindrome library
add_library(palindrome STATIC palindrome.c)

# Add the executable for the test
add_executable(test_palindrome test_palindrome.c)

# Link the palindrome library to the test executable
target_link_libraries(test_palindrome PRIVATE palindrome)

# Enable testing
enable_testing()

# Add a test
add_test(NAME palindrome_test COMMAND test_palindrome)
