#include <stdio.h>
#include "rotate_array.h"
#include <assert.h>

void test_return_rotated_element() {
    // Test case 1
    int array1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int rotations1 = 2;
    int index1 = 3;
    int expected1 = 2;
    int result1 = return_rotated_element(array1, size1, rotations1, index1);
    assert(result1 == expected1);

    // Test case 2
    int array2[] = {5, 6, 7, 8, 9, 10};
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int rotations2 = 3;
    int index2 = 1;
    int expected2 = 9;
    int result2 = return_rotated_element(array2, size2, rotations2, index2);
    assert(result2 == expected2);

    // Test case 3
    int array3[] = {1, 2, 3, 4, 5, 6, 7};
    int size3 = sizeof(array3) / sizeof(array3[0]);
    int rotations3 = 3;
    int index3 = 0;
    int expected3 = 5;
    int result3 = return_rotated_element(array3, size3, rotations3, index3);
    assert(result3 == expected3);

    // Test case 4
    int array4[] = {1, 2, 3, 4};
    int size4 = sizeof(array4) / sizeof(array4[0]);
    int rotations4 = 2;
    int index4 = 1;
    int expected4 = 4;
    int result4 = return_rotated_element(array4, size4, rotations4, index4);
    assert(result4 == expected4);

    // Test case 5
    int array5[] = {-1, -100, 3, 99};
    int size5 = sizeof(array5) / sizeof(array5[0]);
    int rotations5 = 2;
    int index5 = 1;
    int expected5 = 99;
    int result5 = return_rotated_element(array5, size5, rotations5, index5);
    assert(result5 == expected5);

    // Test case 6
    int array6[] = {1, 2};
    int size6 = sizeof(array6) / sizeof(array6[0]);
    int rotations6 = 3;
    int index6 = 0;
    int expected6 = 2;
    int result6 = return_rotated_element(array6, size6, rotations6, index6);
    assert(result6 == expected6);
}

int main() {
    test_return_rotated_element();
    return 0;
}