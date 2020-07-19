#pragma once
#include <stdbool.h>

/*
 *哈希表相关说明：
 *HASH_RESULT 类型为相关函数的返回类型
 *HashEntry 为哈希表所保存元素（即键值对 《key, value》）类型
 *HashTable 为哈希表，其中 bucket 指向大小为size的、元素类型为 HashEntry*的指针数组
 *哈希表采用链地址法处理冲突
 *请实现 create_hash 函数，创建指定大小的哈希表。
 */

typedef enum
{
    HASH_OK,
    HASH_ERROR,
    HASH_ADDED,
    HASH_REPLACED_VALUE,
    HASH_ALREADY_ADDED,
    HASH_DELETED,
    HASH_NOT_FOUND,
} HASH_RESULT;

typedef struct __HashEntry HashEntry;

struct __HashEntry
{
    union
    {
        char  *str_value;
        double dbl_value;
        int    int_value;
    } key;

    union
    {
        char*  str_value;
        double dbl_value;
        int    int_value;
        long   long_value;
        void*  ptr_value;
    } value;
    
    HashEntry *next;
};

struct __HashTable
{
    HashEntry** bucket;        
    int size;
    HASH_RESULT last_error;
};

typedef struct __HashTable HashTable;

HashTable* create_hash(int hash_size);
long hash_string(const char *str);
HASH_RESULT hash_add_int(HashTable *table, const char *key, int value);
void destroy_hash(HashTable* t);
bool hash_find_int(HashTable *table, const char *key);