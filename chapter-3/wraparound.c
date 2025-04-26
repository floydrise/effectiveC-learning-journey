#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* Written as is, the program will output "We all good" even tho we are not good at all.
This is an example of unsigned integer wraparound. Two possible solutions - cast to unsigned long as is in the
comment inside the if-statement, or perform modulo arithmetic */

int main(void) {
  unsigned int ui = UINT_MAX;
  unsigned int sum = 1;
  if (/* (unsigned long) */ ui + sum > UINT_MAX) { // <- this | or -> if (sum > UINT_MAX - ui)
    printf("Too big\n");
  } else {
    printf("We all good\n");
  };
  return EXIT_SUCCESS;
};