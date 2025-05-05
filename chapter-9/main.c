#include "header_exercise.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a = 12;
  int b = 15;
  int result = sum(a, b);
  printf("%d\n", result);
  printf("%lu", __STDC_VERSION__);
  return EXIT_SUCCESS;
}