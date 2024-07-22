#include <stdio.h>
#include "plus_one.h"

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* result;
    *returnSize = digitsSize;
    
    int plusValue = 1;
    
    // Check if all digits are 9.
    int index = 0;
    for (; index<digitsSize; index++) {
        if (digits[index] != 9) {
            break;
        }
    }
    if (index == digitsSize) {
        (*returnSize)++;
        result = (int *)malloc(sizeof(int)*(*returnSize));
        result[0] = 1;
        for (int i=1; i<(*returnSize); i++) {
            result[i] = 0;
        }
        return result;
    }
    
    result = (int *)malloc(sizeof(int)*(*returnSize));
    index = (*returnSize) - 1;
    int current = digits[index] + plusValue;
    result[index] = current % 10;
    int carry = current / 10;
    index--;
    for (; index>=0; index--) {
        current = digits[index] + carry;
        result[index] = current % 10;
        carry = current / 10;
    }
     
    return result;
}

