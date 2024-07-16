#include <stdio.h>
#include "memory_layout.h"

void say_hello() {
    printf("Hello, World!\n");
}

char* allocate_heap() {
    printf("Allocating heap\n");
    char *heap = (char *) malloc(heap_size);
    if (heap == NULL) {
        printf("Failed to allocate heap\n");
    } else {
        printf("Heap allocated at %p\n", (void *) heap);
        // Fill the heap with a random value
        for (int i = 0; i < heap_size; i++) {
            heap[i] = 'A' + (i % 26);
        }
    }
    return heap;
}

void deallocate_heap(char *heap) {
    printf("Deallocating heap\n");
    // Deallocate the heap
    free(heap);
    printf("Heap deallocated\n");
}

void print_memory_layout() {
    printf("Memory Layout\n");
    printf("-------------\n");
    printf("Code Segment: %p\n", (void *) &say_hello);
    printf("Data Segment: %p\n", (void *) &print_memory_layout);
    printf("Heap Segment: %p\n", (void *) malloc(1));
    int stack_var = 0;
    printf("Stack Segment: %p\n", (void *) &stack_var);
}
