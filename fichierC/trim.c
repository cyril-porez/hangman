#include <ctype.h>
#include <string.h>

void trim(char *str) {
    char *p = str;
    int l = strlen(p);

    while(isspace(p[l - 1])) p[--l] = 0;
    while(* p && isspace(* p)) ++p, --l;

    memmove(str, p, l + 1);
}