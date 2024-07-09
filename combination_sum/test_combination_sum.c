#include <stdio.h>
#include <assert.h>
#include "combination_sum.h"

void test_combination_sum() {
    printf("Test combination_sum\n");

    // Test case 1
    int candidates1[] = {2, 3, 6, 7};
    int candidates_size1 = sizeof(candidates1) / sizeof(candidates1[0]);
    int target1 = 7;
    int return_size1;
    int* return_column_sizes1;
    int** result1 = combination_sum(candidates1, candidates_size1, target1, &return_size1, &return_column_sizes1);

    assert(return_size1 == 2);
    assert(return_column_sizes1[0] == 3);
    assert(return_column_sizes1[1] == 1);

    printf("Test case 1 passed\n");

    // Test case 2
    int candidates2[] = {2, 3, 5};
    int candidates_size2 = sizeof(candidates2) / sizeof(candidates2[0]);
    int target2 = 8;
    int return_size2;
    int* return_column_sizes2;
    int** result2 = combination_sum(candidates2, candidates_size2, target2, &return_size2, &return_column_sizes2);

    assert(return_size2 == 3);
    assert(return_column_sizes2[0] == 4);
    assert(return_column_sizes2[1] == 3);
    assert(return_column_sizes2[2] == 2);

    printf("Test case 2 passed\n");
}

int main() {
    test_combination_sum();
    return 0;
}