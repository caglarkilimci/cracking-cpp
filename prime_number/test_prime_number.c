#include <stdio.h>
#include "prime_number.h"

// Test is_prime function
void test_is_prime() {
    printf("Test is_prime\n");

    // Test cases
    int test_cases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    // Iterate over test cases
    for (int i = 0; i < num_test_cases; i++) {
        int result = is_prime(test_cases[i]);
        if (result == 0) {
            printf("Test case %d passed.\n", test_cases[i]);
        } else {
            printf("Test case %d failed.\n", test_cases[i]);
        }
    }
}

int main() {
    test_is_prime();
    return 0;
}
