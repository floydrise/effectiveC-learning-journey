#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  const char *str = "howdy"; // static global string literal
  char str_arr[6] = "howdy"; // stack allocated char array
  printf("%s\n", str_arr);
  char *str_cpy = strdup(str); // heap allocated copy of the string literal, shorthand for malloc() + strcpy()
  if (str_cpy != NULL) {
    printf("%s\n", str_cpy);
    free(str_cpy);
    str_cpy = NULL;
  };
  return EXIT_SUCCESS;
};