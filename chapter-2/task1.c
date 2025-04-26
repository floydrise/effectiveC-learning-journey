// “1.  Add a retrieve function to the counting example from Listing 2-6 to
// retrieve the current value of counter.”
#include <stdio.h>

int fred = 0;

void increment(void) {
  fred++;
  printf("%d \n", fred);
}

int retrieve() { return fred; };

int main(void) {
  for (int i = 0; i < 5; i++) {
    increment();
    printf("Current: %d\n", retrieve());
  }
  return 0;
}