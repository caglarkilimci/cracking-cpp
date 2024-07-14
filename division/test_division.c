#include <stdio.h>
#include "division.h"

// Test division
void test_division() {
    printf("Test division\n");

    // Test case 1
    int result1 = division(10, 2);
    if (result1 == 5) {
        printf("Test case 1 passed\n");
    } else {
        printf("Test case 1 failed\n");
    }

    // Test case 2
    int result2 = division(15, 3);
    if (result2 == 5) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
    }

    // Test case 3
    int result3 = division(10, 3);
    if (result3 == 3) {
        printf("Test case 3 passed\n");
    } else {
        printf("Test case 3 failed\n");
    }
}

int main() {
    test_division();
    return 0;
}
