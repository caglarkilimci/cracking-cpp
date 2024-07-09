#include <stdio.h>
#include "longest_substring.h"

// Test longest_substring
void test_longest_substring() {
    printf("Test longest_substring\n");

    // Test case 1: Empty string
    const char *s1 = "";
    int result1 = longest_substring(s1);
    printf("Input: \"%s\", Expected Output: 0, Actual Output: %d\n", s1, result1);

    // Test case 2: String with no repeating characters
    const char *s2 = "abcdefg";
    int result2 = longest_substring(s2);
    printf("Input: \"%s\", Expected Output: 7, Actual Output: %d\n", s2, result2);

    // Test case 3: String with repeating characters
    const char *s3 = "abcabcbb";
    int result3 = longest_substring(s3);
    printf("Input: \"%s\", Expected Output: 3, Actual Output: %d\n", s3, result3);

    // Test case 4: String with all repeating characters
    const char *s4 = "bbbbb";
    int result4 = longest_substring(s4);
    printf("Input: \"%s\", Expected Output: 1, Actual Output: %d\n", s4, result4);

    // Test case 5: String with 1 character
    const char *s5 = "a";
    int result5 = longest_substring(s5);
    printf("Input: \"%s\", Expected Output: 1, Actual Output: %d\n", s5, result5);

    // Test case 6: String with repeating characters at the end
    const char *s6 = "pwwkew";
    int result6 = longest_substring(s6);
    printf("Input: \"%s\", Expected Output: 3, Actual Output: %d\n", s6, result6);
}

int main() {
    test_longest_substring();
    return 0;
}