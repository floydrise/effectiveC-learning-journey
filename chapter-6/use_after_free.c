// this is just an exercise, it wouldn't compile as is, but the error from the book is resolved
/* #include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int closedir(DIR *dirp) {
  int result = close(dirp->d_fd);
  free(dirp->d_buf);
  free(dirp);
  return result;
} */