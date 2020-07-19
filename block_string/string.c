#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"

/*
 *字符串初始化函数
 */
void blstr_init(BLString *T) 
{
    T->len = 0;
    T->head = NULL;
    T->tail = NULL;
}
/*
 *字符串创建赋值函数
 */
int StrSet(BLString *s, char *t)
{
    if (t == NULL || t[0] == '\0') 
        return 0;
    
    blstr_init(s);
    Block* p; int i;

    while (*t)
    {
        p = (Block*)malloc(sizeof(Block));
        p->next = NULL;
        for (i = 0; i < BLOCK_SIZE && *t != '\0'; ++i, ++t)
        {
            p->ch[i] = *t;
            ++s->len;
        }
            
        for (; i < BLOCK_SIZE; ++i)
            p->ch[i] = '#';

        if (s->head == NULL)
            s->head = p;
        else
            s->tail->next = p;
        s->tail = p;
    }
    return s->len;
}

/*
 *字符串打印函数
 */
int StrPrint(BLString *s)
{
    Block* p; char *t; int i;
    
    if (s == NULL || s->head == NULL)
        return 0;
        
    p = s->head;
    while (p != NULL)
    {
        t = p->ch;
        for (i = 0; i < BLOCK_SIZE && *t != '#'; ++i, ++t)
            putchar(*t);
        p = p->next;
    }

    return s->len;
}

/*
 *字符串清除函数
 */
void StrClear(BLString *s)
{
    Block *p, *q;

    if (s == NULL) 
        return;

    p = s->head;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }

    s->head = s->tail = NULL;
    s->len = 0;
}

/*
 *请实现块链串的子串查找操作：
 *bool blstr_substr(BLString src, int pos, int len, BLString *sub);
 *src为要查找的字符串
 *pos为子串开始的下标
 *len为子串的长度
 *sub在函数调用运行前指向一个已经初始化好的空串，在函数返回时，sub指向串src从第pos个字符起长度为len的子串
 *函数查找成功返回true，参数不正确返回 false
 */
bool blstr_substr(BLString src, int pos, int len, BLString *sub)
{
    if(len <= 0 || pos >= src.len || pos < 0)
        return false;
    
    for(int i = 0; i < pos/BLOCK_SIZE; i++)
    {
        if(src.head->next)
            src.head = src.head->next;
        else
            return false;
    }

    int m = 1;
    int n = pos % BLOCK_SIZE + 1;
    sub->head = (Block*)malloc(sizeof(Block));
    sub->head->next = NULL;
    sub->tail = sub->head;

    while(sub->len < len)
    {
        if( n > BLOCK_SIZE)
        {
            n = n % BLOCK_SIZE;
            if(src.head->next)
                src.head = src.head->next;
            else
                break;  
        }

        if (src.head->ch[n - 1] != BLS_BLANK) 
        {
            if( m > BLOCK_SIZE )
            {
                m = m % BLOCK_SIZE;
                sub->tail->next = (Block*)malloc(sizeof(Block));
                if(sub->tail->next)
                {
                    sub->tail = sub->tail->next;
                    sub->tail->next = NULL;
                }
                else
                    return false;
            }
            sub->tail->ch[m - 1] = src.head->ch[n - 1];
            m++; n++;
            sub->len++;
        } 
        else
            break;
    }
    
    for (;m > 1 && m <= BLOCK_SIZE; m++)
        sub->tail->ch[m - 1] = BLS_BLANK;
    
    return true;
}