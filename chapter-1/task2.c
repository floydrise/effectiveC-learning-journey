// “2.  Declare an array of three pointers to functions and invoke the
// appropriate function based on an index value passed in as an argument.”
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void fn1(void) { printf("Hello from fn1\n"); };

void fn2(void) { printf("Hello from fn2\n"); };

void fn3(void) { printf("Hello from fn3\n"); };

void invokeFnByIndex(uint32_t index) {
  void (*fnArr[3])() = {fn1, fn2, fn3};

  if (index >= 0 && index <= 2) {
    (*fnArr[index])();
  } else {
    printf("Index out of bound: %d\n", index);
  }
};

int main(void) {
  for (uint32_t i = 0; i < 4; i++) {
    invokeFnByIndex(i);
  }
  return EXIT_SUCCESS;
};