#include <stdbool.h>

#define BLOCK_SIZE 4    // 可由用户定义的块大小
#define BLS_BLANK '#'   // 用于空白处的补齐字符

typedef struct _block 
{
    char ch[BLOCK_SIZE];    //块的数据域
    struct _block *next;    //块的指针域
} Block;

typedef struct 
{
    Block *head;        // 串的头指针
    Block *tail;        // 串的尾指针
    int len;            // 串的当前长度
} BLString;


void blstr_init(BLString *T) ;
int StrSet(BLString *s, char *t);
int StrPrint(BLString *s);
void StrClear(BLString *s);
bool blstr_substr(BLString src, int pos, int len, BLString *sub);
