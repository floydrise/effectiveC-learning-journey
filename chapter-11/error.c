#include <stdlib.h>
#include <sys/_types/_errno_t.h>
#include <sys/_types/_rsize_t.h>

char *get_error(errno_t errnum) {
  rsize_t size = strerrorlen_s(errnum) + 1;
  char *msg = malloc(size);
  if (msg != NULL) {
    errno_t status = strerror_s(msg, size, errnum);
    if (status != 0)
      return NULL;
  }
  return msg;
}