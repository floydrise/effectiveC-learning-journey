#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  FILE *fptr;
  char str[99];
  int status = EXIT_SUCCESS;
  if ((fptr = fopen("new_file.txt", "r")) == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  int n = fscanf(fptr, "%98[^\n]", str);

  if (n == 1) {
    printf("%s\n", str);
  } else if (ferror(fptr)) {
    perror("Error indicated");
    status = EXIT_FAILURE;
  } else if (feof(fptr)) {
    printf(stderr, "Unexpected end of file\n");
    status = EXIT_FAILURE;
  } else {
    puts("An error occured");
    status = EXIT_FAILURE;
  }

  if (fclose(fptr) == EOF) {
    perror("fclose");
    status = EXIT_FAILURE;
  }
  return status;
}