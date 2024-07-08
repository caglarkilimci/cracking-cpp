#include <stdio.h>
#include "palindrome.h"

// is_string_palindrome function definition
// Returns 0 if the string is palindrome, 1 otherwise
int is_string_palindrome(char *str) {
    if (str == NULL) {
        return 1; // handle null pointer case
    }
    
    int length = 0;
    while (str[length] != '\0') {
        length++; // calculate the length of the string
    }
    
    int start = 0;
    int end = length - 1;
    
    while (start < end) {
        if (str[start] != str[end]) {
            return 1; // not a palindrome
        }
        start++;
        end--;
    }
    
    return 0; // palindrome
}

