#include <stdio.h>
#include <string.h>
#include "reverse_string.h"

// Test reverse_string
void test_reverse_string() {
    printf("Test reverse_string\n");

    // Test case 1: Empty string
    char str1[] = "";
    reverse_string(str1);
    if (strcmp(str1, "") == 0) {
        printf("Test case 1 passed.\n");
    } else {
        printf("Test case 1 failed.\n");
        printf("Expected: \"\"\n");
        printf("Got: \"%s\"\n", str1);
    }

    // Test case 2: Single character string
    char str2[] = "A";
    reverse_string(str2);
    if (strcmp(str2, "A") == 0) {
        printf("Test case 2 passed.\n");
    } else {
        printf("Test case 2 failed.\n");
        printf("Expected: \"A\"\n");
        printf("Got: \"%s\"\n", str2);
    }

    // Test case 3: String with even length
    char str3[] = "Hello";
    reverse_string(str3);
    if (strcmp(str3, "olleH") == 0) {
        printf("Test case 3 passed.\n");
    } else {
        printf("Test case 3 failed.\n");
        printf("Expected: \"olleH\"\n");
        printf("Got: \"%s\"\n", str3);
    }

    // Test case 4: String with odd length
    char str4[] = "World";
    reverse_string(str4);
    if (strcmp(str4, "dlroW") == 0) {
        printf("Test case 4 passed.\n");
    } else {
        printf("Test case 4 failed.\n");
        printf("Expected: \"dlroW\"\n");
        printf("Got: \"%s\"\n", str4);
    }
}

int main() {
    test_reverse_string();
    return 0;
}