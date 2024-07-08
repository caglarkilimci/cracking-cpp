#include <stdio.h>
#include "reverse_string.h"

// reverse_string function definition
void reverse_string(char* str) {
    if (str == NULL) {
        return; // handle null pointer case
    }
    
    int length = 0;
    while (str[length] != '\0') {
        length++; // calculate the length of the string
    }
    
    int start = 0;
    int end = length - 1;
    
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}


