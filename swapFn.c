#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
};

int main(void) {
  int a = 12;
  int b = 14;
  printf("a = %d | b = %d\n", a, b); // prints 12 and 14
  swap(&a, &b);
  printf("a = %d | b = %d\n", a, b); // swaps values -> prints 14 and 12
  return EXIT_SUCCESS;
};