#include <stdio.h>
#include "string.h"

#define EOL putchar('\n')

int main()
{
    BLString s;
    StrSet(&s, "abcdefghijklmnopqrstuvwxyABCDEFGHIJKLMNOPQRSTUVWXY0");
    StrPrint(&s);
    EOL;

    BLString t;
    blstr_init(&t);
    blstr_substr(s, 15, 38, &t);
    StrPrint(&t);
    EOL;

    StrClear(&s);
    StrClear(&t);

    return 0;
}