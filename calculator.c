#include <stdio.h>
#include <stdlib.h>

// Simple calculator made as an exercise, will be revisited :)
int main(void) {
  float first_var;
  char operator;
  float second_var;
  float result;
  system("clear");
  printf("Input first variable: ");
  scanf("%f", &first_var);
  printf("Input operator (*, /, +, -): ");
  scanf(" %c", &operator);
  printf("Input second variable: ");
  scanf("%f", &second_var);
  switch (operator) {
  case '*':
    result = first_var * second_var;
    break;
  case '/':
    result = first_var / second_var;
    break;
  case '+':
    result = first_var + second_var;
    break;
  case '-':
    result = first_var - second_var;
    break;
  };
  result == (int)result ? printf("Result is: %d\n", (int)result)
                        : printf("Result is: %f\n", result);
  return EXIT_SUCCESS;
}