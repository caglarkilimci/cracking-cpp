#include <stdio.h>
#include <assert.h>
#include "reverse_integer.h"

void test_reverse() {
    printf("Test reverse\n");

    // Test case 1: Positive number
    int result = reverse(123);
    printf("Reverse of 123: %d\n", result);
    assert(result == 321);

    // Test case 2: Negative number
    result = reverse(-456);
    printf("Reverse of -456: %d\n", result);
    assert(result == -654);

    // Test case 3: Zero
    result = reverse(0);
    printf("Reverse of 0: %d\n", result);
    assert(result == 0);

    // Test case 4: Overflow
    result = reverse(2147483647); // INT_MAX
    printf("Reverse of 2147483647: %d\n", result);
    assert(result == 0);

    // Test case 5: Underflow
    result = reverse(-2147483648); // INT_MIN
    printf("Reverse of -2147483648: %d\n", result);
    assert(result == 0);
}

int main() {
    test_reverse();
    return 0;
}
