#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *str = "howdy";
  char *str_cpy = strdup(str);
  if (str_cpy != NULL) {
    printf("%s\n", str_cpy);
    free(str_cpy);
  };
  return EXIT_SUCCESS;
};