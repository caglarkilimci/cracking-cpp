#include <stdio.h>
#include "fibonacci.h"

// Simple assertion function
void assert_equal(long long expected, long long actual, const char* test_name) {
    if (expected == actual) {
        printf("%s passed.\n", test_name);
    } else {
        printf("%s failed: expected %lld but got %lld.\n", test_name, expected, actual);
    }
}

void test_fibonacci_recursion() {
    assert_equal(0, fibonacci_recursion(0), "Test Fibonacci Recursion 0");
    assert_equal(1, fibonacci_recursion(1), "Test Fibonacci Recursion 1");
    assert_equal(1, fibonacci_recursion(2), "Test Fibonacci Recursion 2");
    assert_equal(2, fibonacci_recursion(3), "Test Fibonacci Recursion 3");
    assert_equal(3, fibonacci_recursion(4), "Test Fibonacci Recursion 4");
    assert_equal(5, fibonacci_recursion(5), "Test Fibonacci Recursion 5");
    assert_equal(8, fibonacci_recursion(6), "Test Fibonacci Recursion 6");
}

void test_fibonacci_iteration() {
    assert_equal(0, fibonacci_iteration(0), "Test Fibonacci Iteration 0");
    assert_equal(1, fibonacci_iteration(1), "Test Fibonacci Iteration 1");
    assert_equal(1, fibonacci_iteration(2), "Test Fibonacci Iteration 2");
    assert_equal(2, fibonacci_iteration(3), "Test Fibonacci Iteration 3");
    assert_equal(3, fibonacci_iteration(4), "Test Fibonacci Iteration 4");
    assert_equal(5, fibonacci_iteration(5), "Test Fibonacci Iteration 5");
    assert_equal(8, fibonacci_iteration(6), "Test Fibonacci Iteration 6");
}

int main() {
    test_fibonacci_recursion();
    test_fibonacci_iteration();
    return 0;
}
