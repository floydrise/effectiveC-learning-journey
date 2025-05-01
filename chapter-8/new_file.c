#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  FILE *fptr;
  fptr = fopen("new_file.txt", "w");
  if (fptr == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }
  char str[] = "This is the text I want to write into the txt file named "
               "new_file.txt :)";

  size_t str_len = strlen(str);
  size_t ret_val = fwrite(str, sizeof(char), str_len, fptr);

  if (ret_val < str_len) {
    perror("fwrite");
    fclose(fptr);
    return EXIT_FAILURE;
  }

  printf("File successfuly created and filled");

  if (fclose(fptr) == EOF) {
    perror("fclose");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}