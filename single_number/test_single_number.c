#include <stdio.h>
#include "single_number.h"

// Test singleNumber
void test_singleNumber() {
    printf("Test singleNumber\n");

    // Test case 1
    int nums1[] = {2, 2, 1};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int expected1 = 1;
    int result1 = singleNumber(nums1, numsSize1);
    printf("Expected: %d, Result: %d\n", expected1, result1);

    // Test case 2
    int nums2[] = {4, 1, 2, 1, 2};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int expected2 = 4;
    int result2 = singleNumber(nums2, numsSize2);
    printf("Expected: %d, Result: %d\n", expected2, result2);

    // Test case 3
    int nums3[] = {1};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    int expected3 = 1;
    int result3 = singleNumber(nums3, numsSize3);
    printf("Expected: %d, Result: %d\n", expected3, result3);
}

int main() {
    test_singleNumber();
    return 0;
}
