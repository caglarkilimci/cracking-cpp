#include <stdio.h>
#include <string.h>
#include "palindrome.h"

// Test is_string_palindrome
void test_is_string_palindrome() {
    printf("Test is_string_palindrome\n");

    // Test case 1: Palindrome string
    char str1[] = "level";
    int result1 = is_string_palindrome(str1);
    if (result1 == 0) {
        printf("Test case 1 passed.\n");
    } else {
        printf("Test case 1 failed.\n");
    }

    // Test case 2: Non-palindrome string
    char str2[] = "hello";
    int result2 = is_string_palindrome(str2);
    if (result2 == 1) {
        printf("Test case 2 passed.\n");
    } else {
        printf("Test case 2 failed.\n");
    }

    // Test case 3: Empty string
    char str3[] = "";
    int result3 = is_string_palindrome(str3);
    if (result3 == 0) {
        printf("Test case 3 passed.\n");
    } else {
        printf("Test case 3 failed.\n");
    }
}

int main() {
    test_is_string_palindrome();
    return 0;
}