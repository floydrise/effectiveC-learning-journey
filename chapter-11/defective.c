#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define name_size 10U

/* ------------------------------------------------------------------------------------
Output from scan-build LLVM Clang static analyser:
scan-build: Using '/opt/homebrew/Cellar/llvm/20.1.4/bin/clang-20' for static
analysis scan-build: Analysis run complete. scan-build: Removing directory
'/var/folders/6s/v8zwddjd5zb92xnbrwfwhb940000gn/T/scan-build-2025-05-07-225731-20091-1'
because it contains no reports. scan-build: No bugs found. Unfortunately it did
not catch the error :(
--------------------------------------------------------------------------------------- */

char *vstrcat(char *buff, size_t buff_length, ...) {
  char *ret = buff;
  va_list list;
  va_start(list, buff_length);

  const char *part = NULL;
  size_t offset = 0;
  while ((part = va_arg(list, const char *))) {
    buff = (char *)memccpy(buff, part, '\0', buff_length - offset) - 1;
    if (buff == NULL) {
      ret[0] = '\0';
      break;
    }
    offset = buff - ret;
  }

  va_end(list);
  return ret;
}

int main() {
  char name[name_size] = "";
  char first[] = "Stefan";
  char middle[] = "A.";
  char last[] = "Petrov";

  puts(vstrcat(name, sizeof(name), first, " ", middle, " ", last, NULL));
}