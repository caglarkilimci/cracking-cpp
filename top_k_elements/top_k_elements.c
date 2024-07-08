#include <stdio.h>
#include <stdlib.h>
#include "top_k_elements.h"

// Top K elements function definition
int * top_k_elements(int *arr, int n, int k) {
    if (arr == NULL || n <= 0 || k <= 0 || k > n) {
        return NULL; // handle invalid input
    }
    
    // Build a max heap from the array
    build_max_heap(arr, n);
    
    // Allocate memory for the top k elements
    int *top_k = (int *)malloc(k * sizeof(int));
    if (top_k == NULL) {
        return NULL; // handle memory allocation failure
    }
    
    // Extract the top k elements from the max heap
    for (int i = 0; i < k; i++) {
        top_k[i] = extract_max(arr, n - i);
    }
    
    return top_k;
}

// Function to build a max heap from the array
void build_max_heap(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to heapify a subtree rooted at index i
void heapify(int *arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child
    
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to extract the maximum element from the max heap
int extract_max(int *arr, int n) {
    int max = arr[0]; // Store the maximum value
    
    // Replace the root of the heap with the last element
    arr[0] = arr[n - 1];
    
    // Reduce the size of the heap
    n--;
    
    // Heapify the root node
    heapify(arr, n, 0);
    
    return max;
}

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
