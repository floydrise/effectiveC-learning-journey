#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int arr[5] = {1, 3, 3, 4, 5};
  printf("Value\tAddress\n");
  for (size_t i = 0; i < 5; ++i) {
    printf("%d\t%p\n", *(arr + i), (void *)(arr + i));
  }
  return EXIT_SUCCESS;
}