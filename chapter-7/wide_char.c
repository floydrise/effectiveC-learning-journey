
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main(void) {
  setlocale(LC_ALL, "");
  wchar_t emoji = L'й';
  size_t emoji_len = wcslen(&emoji);
  wprintf(L"%lc\n", emoji);
  printf("%lu\n", emoji_len);
  
  return EXIT_SUCCESS;
};