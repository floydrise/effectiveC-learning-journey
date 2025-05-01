#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  FILE *fptr;
  fptr = fopen("new_file.txt", "w");
  if (fptr == NULL) {
    printf("File cannot be created!");
    return EXIT_FAILURE;
  }
  char str[] = "This is the text I want to write into the txt file named "
               "new_file.txt :)";

  size_t ret_val = fwrite(str, sizeof(char), strlen(str), fptr);

  if (ret_val == strlen(str)) {
    printf("File successfuly created and filled");
  }

  fclose(fptr);
  return EXIT_SUCCESS;
}