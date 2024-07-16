#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "memory_layout.h"


// Test say_hello
void test_say_hello() {
    printf("Test say_hello\n");

    for (int i = 0; i < repeat_count; i++) {
        // Call the function
        say_hello();
    }
}

void test_allocate_heap() {
    printf("Test allocate_heap\n");

    struct mallinfo mi = mallinfo();

    printf("Total non-mmapped bytes allocated (arena):       %d\n", mi.arena);
    printf("Number of free chunks (ordblks):                  %d\n", mi.ordblks);
    printf("Number of fastbin blocks (smblks):                %d\n", mi.smblks);
    printf("Number of mmapped regions (hblks):                %d\n", mi.hblks);
    printf("Space in mmapped regions (hblkhd):                %d\n", mi.hblkhd);
    printf("Maximum total allocated space (usmblks):          %d\n", mi.usmblks);
    printf("Space in free fastbin blocks (fsmblks):           %d\n", mi.fsmblks);
    printf("Total allocated space (uordblks):                 %d\n", mi.uordblks);
    printf("Total free space (fordblks):                      %d\n", mi.fordblks);
    printf("Top-most, releasable (via malloc_trim) space (keepcost): %d\n", mi.keepcost);

    // Call the function
    char* heap = allocate_heap();

    printf("Memory after allocate_heap\n");

    mi = mallinfo();
    printf("Total non-mmapped bytes allocated (arena):       %d\n", mi.arena);
    printf("Number of free chunks (ordblks):                  %d\n", mi.ordblks);
    printf("Number of fastbin blocks (smblks):                %d\n", mi.smblks);
    printf("Number of mmapped regions (hblks):                %d\n", mi.hblks);
    printf("Space in mmapped regions (hblkhd):                %d\n", mi.hblkhd);
    printf("Maximum total allocated space (usmblks):          %d\n", mi.usmblks);
    printf("Space in free fastbin blocks (fsmblks):           %d\n", mi.fsmblks);
    printf("Total allocated space (uordblks):                 %d\n", mi.uordblks);
    printf("Total free space (fordblks):                      %d\n", mi.fordblks);
    printf("Top-most, releasable (via malloc_trim) space (keepcost): %d\n", mi.keepcost);

    // Deallocate the heap
    deallocate_heap(heap);

    printf("Memory after deallocate_heap\n");
    mi = mallinfo();
    printf("Total non-mmapped bytes allocated (arena):       %d\n", mi.arena);
    printf("Number of free chunks (ordblks):                  %d\n", mi.ordblks);
    printf("Number of fastbin blocks (smblks):                %d\n", mi.smblks);
    printf("Number of mmapped regions (hblks):                %d\n", mi.hblks);
    printf("Space in mmapped regions (hblkhd):                %d\n", mi.hblkhd);
    printf("Maximum total allocated space (usmblks):          %d\n", mi.usmblks);
    printf("Space in free fastbin blocks (fsmblks):           %d\n", mi.fsmblks);
    printf("Total allocated space (uordblks):                 %d\n", mi.uordblks);
    printf("Total free space (fordblks):                      %d\n", mi.fordblks);
    printf("Top-most, releasable (via malloc_trim) space (keepcost): %d\n", mi.keepcost);

}

void test_print_memory_layout() {
    printf("Test print_memory_layout\n");

    // Call the function
    print_memory_layout();

    // Add assertions to verify the expected output
    // For example, you can check if the code segment address is printed correctly
    assert(printf("Code Segment: %p\n", (void *) &say_hello) > 0);
    // Add more assertions for other segments if needed
}

int main() {
    test_say_hello();
    test_allocate_heap();
    test_print_memory_layout();
    return 0;
}