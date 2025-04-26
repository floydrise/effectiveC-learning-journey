#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// take overflow into consideration
// if argument passed is equal to INT_MIN,
// fn will return 0 instead of undefined behaviour
int absolute_value(int a) {
  if (a < 0) {
    if (a == INT_MIN) {
      return 0;
    }
    return -a;
  }
  return a;
}

int main(void) {
  int a = INT_MIN;
  int val = absolute_value(a);
  printf("%d\n", val);
  return EXIT_SUCCESS;
}