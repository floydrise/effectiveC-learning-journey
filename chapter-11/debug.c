#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define name_size 20U

char *vstrcat(char *buff, size_t buff_length, ...) {
    char *ret = buff;
    va_list list;
    va_start(list, buff_length);

    const char *part = NULL;
    size_t offset = 0;
    while ((part = va_arg(list, const char *))) {
        buff = (char *) memccpy(buff, part, '\0', buff_length - offset);
        if (buff == NULL) {
            ret[0] = '\0';
            break;
        }
        offset = --buff - ret;
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
