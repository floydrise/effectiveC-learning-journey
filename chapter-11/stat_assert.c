#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// if prefix's value is instead changed to "Error Number: " a warning will
// appear
int main(void) {
  static constexpr char prefix[] = "Error No: ";
  constexpr int size = 14;
  char str[size];
  static_assert(sizeof(str) > sizeof(prefix), "str must be larger than prefix");
  strcpy(str, prefix);
  printf("%s\n", str);
  return EXIT_SUCCESS;
}
