// small malloc and realloc exercise, not from the book
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int *arrp = malloc(5 * sizeof(*arrp));
  if (arrp == NULL) {
    printf("Allocation failed!");
    return EXIT_FAILURE;
  }
  printf("Original arrp:\n");
  for (size_t i = 0; i < 5; ++i) {
    *(arrp + i) = i;
    printf("%d, ", *(arrp + i));
  }
  int *tmp = realloc(arrp, 8 * sizeof(*arrp));
  if (tmp == NULL) {
    printf("Reallocation failed!");
    return EXIT_FAILURE;
  }
  arrp = tmp;
  tmp = NULL;
  for (size_t i = 5; i < 8; ++i) {
    *(arrp + i) = i;
  }
  printf("\nAfter realloc:\n");
  for (size_t i = 0; i < 8; ++i) {
    printf("%d, ", *(arrp + i));
  }
  printf("\n");
  free(arrp);
  arrp = NULL;
  return EXIT_SUCCESS;
};