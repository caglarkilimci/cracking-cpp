#include <stdio.h>
#include "longest_substring.h"

// Longest Substring Without Repeating Characters
int longest_substring(const char *s) {
    // Check if the string is empty
    if (s == NULL) {
        return 0;
    }

    // Solve using sliding window
    
    // Initialize variables
    int left = 0, right = 0, max = 0;
    
    // Initialize an array to store the last index of each character
    int last_index[128] = {0};

    // Iterate through the string
    while (s[right] != '\0') {
        // Update the left index to the maximum of the current left index and the last index of the current character
        left = (last_index[s[right]] > left) ? last_index[s[right]] : left;
        
        // Update the last index of the current character
        last_index[s[right]] = right + 1;
        
        // Update the maximum length
        max = (right - left + 1 > max) ? right - left + 1 : max;
        
        // Move to the next character
        right++;
    }

    // Return the maximum length
    return max;
}