#include <stdio.h>
#include "string.h"

int main()
{
    char *in = "aaabbbccc";
    int outlen = 14;
    char *oldstr = "cc";
    char *newstr = "12345678";

    char out[outlen];
    
    printf("%d\n",str_replace(in, out, outlen, oldstr, newstr));
    printf("%s\n", out);
    return 0;
}