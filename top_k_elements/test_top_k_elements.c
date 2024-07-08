#include <stdio.h>
#include <assert.h>
#include "top_k_elements.h"

// Test top_k_elements function
void test_top_k_elements() {
    printf("Test top_k_elements\n");

    // Test case 1: Normal input
    int arr1[] = {5, 2, 8, 1, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 3;
    int *result1 = top_k_elements(arr1, n1, k1);
    assert(result1[0] == 9);
    assert(result1[1] == 8);
    assert(result1[2] == 5);
    printf("Test case 1 passed.\n");

    // Test case 2: Empty array
    int arr2[] = {};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 2;
    int *result2 = top_k_elements(arr2, n2, k2);
    assert(result2 == NULL);
    printf("Test case 2 passed.\n");

    // Test case 3: k > n
    int arr3[] = {3, 1, 4, 2};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int k3 = 5;
    int *result3 = top_k_elements(arr3, n3, k3);
    assert(result3 == NULL);
    printf("Test case 3 passed.\n");
}

int main() {
    test_top_k_elements();
    return 0;
}
