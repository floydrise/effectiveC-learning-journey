#include <stdio.h>
#include <stdlib.h>
#include "isprime.h"

bool is_prime(unsigned long long n, unsigned int k) {
  if (n <= 1 || n == 4)
    return false;
  if (n <= 3)
    return true;

  unsigned long long d = n - 1;
  while (d % 2 == 0)
    d /= 2;

  for (; k != 0; --k) {
    if (!miller_rabin_test(d, n))
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  size_t num_args;
  unsigned long long *vals = convert_cmd_line_args(argc, argv, &num_args);

  if (!vals)
    return EXIT_FAILURE;

  for (size_t i = 0; i < num_args; ++i) {
    printf("%llu is %s.\n", vals[i],
           is_prime(vals[i], 100) ? "probably prime" : "not prime");
  }

  free(vals);
  return EXIT_SUCCESS;
}