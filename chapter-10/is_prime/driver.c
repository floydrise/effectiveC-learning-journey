#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static void print_help() {
  puts("primetest num1 [num2 num3 ... numN]\n");
  puts("Tests positive integers for primality.");
  printf("Tests numbers in the range [2-%llu].\n", ULLONG_MAX);
}

static bool convert_arg(const char *arg, unsigned long long *val) {
  char *end;

  // strtoull returns an in-band error indicator; clear errno before the call
  errno = 0;
  *val = strtoull(arg, &end, 10);

  // check for failures where the call returns a sentinel value and sets errno
  if ((*val == ULLONG_MAX) && errno)
    return false;
  if (*val == 0 && errno)
    return false;
  if (end == arg)
    return false;

  // If we got here, the argument conversion was successful.
  // However, we want to allow only values greater than one,
  // so we reject values <= 1.
  if (*val <= 1)
    return false;
  return true;
}

static unsigned long long *convert_cmd_line_args(int argc, const char *argv[],
                                                 size_t *num_args) {
  *num_args = 0;

  if (argc <= 1) {
    // no command line arguments given (the first argument is the
    // name of the program being executed)
    print_help();
    return nullptr;
  }
  unsigned long long *args =
      (unsigned long long *)malloc(sizeof(unsigned long long) * (argc - 1));
  bool failed_conversion = (args == nullptr);
  for (int i = 1; i < argc && !failed_conversion; ++i) {
    // Attempt to convert the argument to an integer. If we
    // couldn't convert it, set failed_conversion to true.
    unsigned long long one_arg;
    failed_conversion |= !convert_arg(argv[i], &one_arg);
    args[i - 1] = one_arg;
  }

  if (failed_conversion) {
    // free the array, print the help, and bail out
    free(args);
    print_help();
    return nullptr;
  }

  *num_args = argc - 1;
  return args;
}

static unsigned long long power(unsigned long long x, unsigned long long y,
                                unsigned long long p) {
  unsigned long long result = 1;
  x %= p;

  while (y) {
    if (y & 1)
      result = (result * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return result;
}

static bool miller_rabin_test(unsigned long long d, unsigned long long n) {
  unsigned long long a = 2 + rand() % (n - 4);
  unsigned long long x = power(a, d, n);

  if (x == 1 || x == n - 1)
    return true;

  while (d != n - 1) {
    x = (x * x) % n;
    d *= 2;

    if (x == 1)
      return false;
    if (x == n - 1)
      return true;
  }
  return false;
}
