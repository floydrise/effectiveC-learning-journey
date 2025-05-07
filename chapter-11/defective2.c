#include <stdio.h>
#include <stdlib.h>

/* --------------------------------------------------------------------------------------------------------
* Running scan-build clang successfuly generated a warning:

defective2.c:6:18: warning: Dereference of null pointer (loaded from variable
'ptr') [core.NullDereference] 6 |   printf("%d\n", *ptr); | ^~~~ 1 warning
generated. scan-build: Analysis run complete. scan-build: 1 bug found.
---------------------------------------------------------------------------------------------------------
*/

int main(void) {
  int *ptr = NULL;
  printf("%d\n", *ptr);
  return EXIT_SUCCESS;
}
