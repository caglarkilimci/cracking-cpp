#include <stdio.h>
#include "plus_one.h"
#include <assert.h>

// Test plusOne
void test_plusOne() {
    printf("Test plusOne\n");

    // Test case 1
    int digits1[] = {1, 2, 3};
    int digitsSize1 = sizeof(digits1) / sizeof(digits1[0]);
    int returnSize1 = 0;
    int* result1 = plusOne(digits1, digitsSize1, &returnSize1);
    assert(returnSize1 == digitsSize1);
    assert(result1[0] == 1);
    assert(result1[1] == 2);
    assert(result1[2] == 4);
    free(result1);

    // Test case 2
    int digits2[] = {9, 9, 9};
    int digitsSize2 = sizeof(digits2) / sizeof(digits2[0]);
    int returnSize2 = 0;
    int* result2 = plusOne(digits2, digitsSize2, &returnSize2);
    assert(returnSize2 == digitsSize2 + 1);
    assert(result2[0] == 1);
    for (int i = 1; i < returnSize2; i++) {
        assert(result2[i] == 0);
    }
    free(result2);
}

int main() {
    test_plusOne();
    return 0;
}