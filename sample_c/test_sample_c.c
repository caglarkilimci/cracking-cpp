#include <stdio.h>
#include "sample_c.h"

// Test say_hello
void test_say_hello() {
    printf("Test say_hello\n");

    // Call the function
    say_hello();

    // Add assertions here if needed
}

int main() {
    test_say_hello();
    return 0;
}