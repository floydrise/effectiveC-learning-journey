#include <locale.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int main(void) {
  setlocale(LC_ALL, "");
  char *str = "hello";
  wchar_t *emoji = L"👀";

  size_t emoji_len = wcslen(emoji);
  size_t str_len = strlen(str);

  wprintf(L"%ls\n", emoji);
  printf("%lu\n", emoji_len);
  printf("%lu\n", str_len);
  
  return EXIT_SUCCESS;
};