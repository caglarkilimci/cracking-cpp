cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(PrimeNumberTests VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the prime_number library
add_library(prime_number STATIC prime_number.c)

# Add the executable for the test
add_executable(test_prime_number test_prime_number.c)

# Link math library
target_link_libraries(prime_number PRIVATE m)

# Link the prime_number library to the test executable
target_link_libraries(test_prime_number PRIVATE prime_number)

# Enable testing
enable_testing()

# Add a test
add_test(NAME PrimeNumberTest COMMAND test_prime_number)