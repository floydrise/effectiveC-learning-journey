#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *fptr;

  fptr = fopen("new_txt.txt", "w");
  if (fptr == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  int fp_ret_val = fputs("Writing some text", fptr);
  if (fp_ret_val == EOF) {
    perror("fputs");
    return EXIT_FAILURE;
  }
  
  if (fclose(fptr) == EOF) {
    perror("fclose");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
};