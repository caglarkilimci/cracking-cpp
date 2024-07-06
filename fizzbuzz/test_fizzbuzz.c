#include <stdio.h>
#include <string.h>
#include "fizzbuzz.h"

// Test FizzBuzz
void test_fizzbuzz() {
    printf("Test FizzBuzz\n");

    // Redirect stdout to a buffer for testing
    char buffer[1024];
    FILE *stream = fmemopen(buffer, sizeof(buffer), "w");
    if (!stream) {
        perror("fmemopen");
        return;
    }
    
    // Save original stdout
    FILE *original_stdout = stdout;
    stdout = stream;
    
    // Run FizzBuzz
    fizzbuzz(15);
    
    // Flush and reset stdout
    fflush(stream);
    stdout = original_stdout;
    fclose(stream);

    // Expected output
    const char* expected_output = "1\n2\nFizz\n4\nBuzz\nFizz\n7\n8\nFizz\nBuzz\n11\nFizz\n13\n14\nFizzBuzz\n";
    
    // Compare the output
    if (strcmp(buffer, expected_output) == 0) {
        printf("Test passed.\n");
    } else {
        printf("Test failed.\n");
        printf("Expected:\n%s", expected_output);
        printf("Got:\n%s", buffer);
    }
}

int main() {
    test_fizzbuzz();
    return 0;
}
