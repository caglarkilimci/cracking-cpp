#include <stdio.h>
#include <math.h>
#include "prime_number.h"

// Prime number function
// Returns 0 if n is a prime number, 1 otherwise
int is_prime(int n) {
    // Check if n is less than or equal to 1
    if (n <= 1) {
        return 1;
    }

    // Check if n is divisible by 2 or 3
    if (n == 2 || n == 3) {
        return 0;
    }

    // Check if n is divisible by any number of the form 6k ± 1, up to sqrt(n)
    int sqrt_n = (int) sqrt(n);
    for (int i = 5; i <= sqrt_n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 1;
        }
    }

    return 0;
}
