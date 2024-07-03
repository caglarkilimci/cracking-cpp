#include <iostream>

// Factorial function using recursion
long long factorial_recursion(long long n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial_recursion(n - 1);
}

// Factorial function using iteration
long long factorial_iteration(long long n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Factorial function using dynamic programming
long long factorial_dp(long long n) {
    long long dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] * i;
    }
    return dp[n];
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Recursion: " << n << "! = " << factorial_recursion(n) << std::endl;
    std::cout << "Iteration: " << n << "! = " << factorial_iteration(n) << std::endl;
    std::cout << "Dynamic P: " << n << "! = " << factorial_dp(n) << std::endl;
    return 0;
}
