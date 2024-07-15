#include <stdio.h>
#include "reverse_integer.h"

int reverse(int x) {
    if (x == INT_MIN || x == INT_MAX) {
        return 0;
    }
    
    int x_abs = abs(x);
    char x_str[20];
    sprintf(x_str, "%d", x_abs);
    
    int x_length = strlen(x_str);
    
    char temp;
    
    for (int i=0; i<x_length / 2; i++) {
        temp = x_str[i];
        x_str[i] = x_str[x_length - i - 1];
        x_str[x_length - i - 1] = temp;
    }
    
    long x_reversed = atol(x_str);

    if (x_reversed > INT_MAX || x_reversed < INT_MIN) {
        return 0;
    }

    return x < 0 ? -x_reversed : x_reversed;
}
