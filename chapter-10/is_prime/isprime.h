#ifndef PRIMETEST_DRIVER_H
#define PRIMETEST_DRIVER_H

#include <stdbool.h>
#include <stddef.h>

static unsigned long long *convert_cmd_line_args(int argc, const char *argv[],
                                                 size_t *num_args);
bool miller_rabin_test(unsigned long long d, unsigned long long n);

#endif // PRIMETEST_DRIVER_H
