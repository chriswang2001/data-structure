#include <stdio.h>
#include "string.h"

/*串比较
 *不调用库函数，自己实现字符串的比较操作：
 *该操作当比较的两个字符是都是字母，且两个字符互为大小写（如a和A、e和E）时认为两个字符相同，否则不同，
 *其比较结果按这两个字符的原值确定。函数的返回值规定如下：
 *返回值 < 0：第一个不匹配的字符在 ptr1 中的值低于 ptr2 中的值
 *返回值 == 0：两个字符串的内容相等
 *返回值 > 0：第一个不匹配的字符在 ptr1 中的值大于在 ptr2 中的值
 */
int str_compare(const char* ptr1, const char* ptr2)
{
    while(*ptr1 != '\0' && *ptr2 != '\0')
    {
        if(*ptr1 == *ptr2 )
        {
            ptr1++;
            ptr2++; 
        }
        else if(*ptr1 >= 'A' && *ptr1 <= 'Z' && *ptr1 - *ptr2 == 'A'-'a')
        {
            ptr1++;
            ptr2++; 
        }
        else if(*ptr1 >= 'a' && *ptr1 <= 'z' && *ptr1 - *ptr2 == 'a'-'A')
        {
            ptr1++;
            ptr2++; 
        }
        else
            break;  
    }

    if(*ptr1 == *ptr2)
        return 0;
    else if (*ptr1 > *ptr2)
        return 1;
    else if(*ptr1 < *ptr2)
        return -1;
    
    return 2;
}

/*串替换
 *不调用库函数，自己实现字符串替换操作：
 *参数说明:
 *in， 原始字符串，保持不变
 *out, 存放替换结果的字符串
 *outlen，out空间的大小
 *oldstr，要替换的旧字符串
 *newstr，替换成的新字符串
 *函数返回成功替换的次数，即有多少个子串被成功替换
 *在替换过程中，任何情况下所得字符串（及结束符）不应该超过 outlen，如果某次替换所得字符串的长度超过 outlen，则不进行这次替换操作，整个替换操作结束。如：
 *原始串为 "aaabbbccc"，outlen 为14, oldstr 为 "c"，newstr 为 "333" 时，两次替换后得 "aaabbb333333c"，此时字符串占用空间为14字节。
 *如果再进行替换，则会超出 out 所占用的空间，所以停止替换操作。此时函数应该返回 2, out指向的串为 "aaabbb333333c"
 *再如：原始串为 "aaabbbccc"，outlen 为10, oldstr 为 "bb"，newstr 为 "123456"，进行替换后所得的串应该为 "aaa123456" （长度为9）与结束符一共占 10 个字节，此时函数应该返回 1。
 */
int str_replace(const char* in, char* out, int outlen, const char* oldstr, const char* newstr)
{
    int count = 0, time = 0;
    int oldlen = str_len(oldstr);
    int newlen = str_len(newstr);

    while(*in)
    {
        if(*in != *oldstr && count + 1 < outlen)
        {
            *out = *in;
            out++; in++; count++;
        }
        else if(count + newlen < outlen)
        {
            char *o = oldstr, *i = in;

            for(;*o == *i && *o ; o++, i++);

            if(!*o)
            {
                char *n = newstr;
                while(*n)
                {
                    *out = *n;
                    out++; n++;
                }
                count += newlen;
                time++;
                for(int k = 0; k < oldlen; k++, in++);
            }
            else if(count + 1 < outlen)
            {
                *out = *in;
                out++; in++; count++;
            }
        }
        else if(count + 1 < outlen)
        {
            *out = *in;
            out++; in++; count++;
        }
        else
            break;
    }
    *out = '\0';
     return time;
}

int str_len(const char* s)
{
    int len;
    for(len = 0; *s ;s++, len++);
    return len;       
}