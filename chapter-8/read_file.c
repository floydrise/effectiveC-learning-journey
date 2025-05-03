#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *fptr;
  if ((fptr = fopen("new_file.txt", "r")) == NULL) {
    perror("Failed to open file");
    return EXIT_FAILURE;
  }
  char output[100];
  if (fgets(output, sizeof(output), fptr) == NULL) {
    perror("Failed to read file");
    return EXIT_FAILURE;
  }
  printf("%s\n", output);
  if (fclose(fptr) == EOF) {
    perror("Failed to close file");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}