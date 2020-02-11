#include <stdlib.h>
#include <kernel/tty.h>
//TODO - Fix for maxint
char* itoa(int value, char* str, int base) {
    int i = 0;
    int cbase = base;
    while (value > 0) {
        str[i] = ((value % cbase) / (cbase/base)) + 48;
        value -= value % cbase;
        cbase *= base;
        i++;
    }
    char fstring[i];
    for (int j = 1; j <= i; j ++) {
        fstring[j - 1] = str[i - j];
    }
    for (int j = 0; j <= i; j++) {
        str[j] = fstring[j];
    }
    str[i] = 0;
    return str;
}