#include <stdio.h>
#include "division.h"

int division (int divide, int divider) {
    int result = 0;
    int sign = 1;
    if (divide < 0) {
        sign = -sign;
        divide = -divide;
    }
    if (divider < 0) {
        sign = -sign;
        divider = -divider;
    }
    while (divide >= divider) {
        int power = 0;
        int temp = divider;
        while (divide >= temp) {
            temp <<= 1;
            power++;
        }
        result += 1 << (power - 1);
        divide -= divider << (power - 1);
    }
    return sign * result;
}
