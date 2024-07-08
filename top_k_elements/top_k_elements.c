#include <stdio.h>
#include "top_k_elements.h"

// Top K elements function definition
int * top_k_elements(int *arr, int n, int k) {
    if (arr == NULL || n <= 0 || k <= 0 || k > n) {
        return NULL; // handle invalid input
    }
    
    // Sort the array in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // Allocate memory for the top k elements
    int *top_k = (int *)malloc(k * sizeof(int));
    if (top_k == NULL) {
        return NULL; // handle memory allocation failure
    }
    
    // Copy the top k elements to the new array
    for (int i = 0; i < k; i++) {
        top_k[i] = arr[i];
    }
    
    return top_k;
}
