#include <stdio.h>
#include "fibonacci.h"

// Fibonacci function using recursion
long long fibonacci_recursion(long long n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);
}

// Fibonacci function using iteration
long long fibonacci_iteration(long long n) {
    long long a = 0, b = 1, c;
    if (n == 0) {
        return a;
    }
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
