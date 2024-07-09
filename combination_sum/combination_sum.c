#include <stdio.h>
#include <stdlib.h>
#include "combination_sum.h"

void backtrack(int* candidates, int candidates_size, int target, int start, int* combination, int combination_size, int** result, int* result_size, int* column_sizes) {
    if (target == 0) {
        // Add the combination to the result
        result[*result_size] = (int*)malloc(combination_size * sizeof(int));
        for (int i = 0; i < combination_size; i++) {
            result[*result_size][i] = combination[i];
        }
        column_sizes[*result_size] = combination_size;
        (*result_size)++;
        return;
    }

    for (int i = start; i < candidates_size; i++) {
        if (candidates[i] > target) {
            // Skip candidates that are larger than the target
            continue;
        }

        // Add the current candidate to the combination
        combination[combination_size] = candidates[i];
        combination_size++;

        // Recursively call backtrack with the updated target and combination
        backtrack(candidates, candidates_size, target - candidates[i], i, combination, combination_size, result, result_size, column_sizes);

        // Remove the current candidate from the combination
        combination_size--;
    }
}

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** combination_sum(int* candidates, int candidates_size, int target, int* return_size, int** return_column_sizes) {
    // Sort the candidates in non-decreasing order
    qsort(candidates, candidates_size, sizeof(int), compare);

    // Allocate memory for the result
    int** result = (int**)malloc(1000 * sizeof(int*));
    int* column_sizes = (int*)malloc(1000 * sizeof(int));
    *return_size = 0;

    // Allocate memory for the combination
    int* combination = (int*)malloc(candidates_size * sizeof(int));

    // Call the backtrack function to find all combinations
    backtrack(candidates, candidates_size, target, 0, combination, 0, result, return_size, column_sizes);

    // Free the memory for the combination
    free(combination);

    // Set the return_column_sizes pointer
    *return_column_sizes = column_sizes;

    return result;
}
