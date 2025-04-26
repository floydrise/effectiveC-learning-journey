#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int main (void) {
    unsigned int a = UINT_MAX;
    signed char b = -1;
    if (a == b) {
        printf("%d == %u\n",b,a);
    }
    return EXIT_SUCCESS;
};