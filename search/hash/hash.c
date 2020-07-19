#include "hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

/*
 *创建大小为hash_size的哈希表，创建成功后返回HashTable类型的指针，否则返回NULL。
 */
HashTable* create_hash(int hash_size)
{
    printf("%d",hash_size);
    
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    if(table == NULL)
        return NULL;

    HashEntry** bucket = (HashEntry**)malloc(hash_size*sizeof(HashEntry*));
    table->bucket = bucket;
    if(bucket == NULL)
    {
        free(table);
        return NULL;
    }
    
    table->size = hash_size;
    memset(bucket, 0, hash_size);
    
    return table;   
}

long hash_string(const char *str)
{
    long hash = 5381;
    int c;

    while ( (c = *(str++)) )
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    if(hash < 0)
        hash *= -1;
    return hash;
}

/*
 *请实现 hash_add_int 函数，向哈希表中添加元素，其中键类型为char*， 元素类型为int。
 *在添加过程中，如果要添加的键值key已在哈希表中，且对应的值value也已存在，则函数返回 HASH_ALREADY_ADDED；
 *如果要添加的键值key已在哈希表中，但对应的值value不同，则函数将value值更新到哈希表中，之后返回 HASH_REPLACED_VALUE；
 *如果要添加的键值key不在哈希表中，则函数创建 HashEntry 类型，并将其加入到哈希表中，且函数返回 HASH_ADDED。
 */
HASH_RESULT hash_add_int(HashTable* table, const char* key, int value)
{
    int keyhash = hash_string(key) % table->size;

    if (table->bucket[keyhash] == NULL) 
    {
        HashEntry* node = (HashEntry*)malloc(sizeof(HashEntry));
        if (!node)
            return HASH_ERROR;
        node->key.str_value = (char*)malloc(100);
        if (node->key.str_value == NULL)
            return HASH_ERROR;
        node->key.str_value = (char*)key;
        node->value.int_value = value;
        node->next = NULL;
        table->bucket[keyhash] = node;

        return HASH_ADDED;
    } 
    else 
    {
        HashEntry* p = table->bucket[keyhash];
        while (p != NULL) 
        {
            if (!strcmp(p->key.str_value, key)) {
                if (p->value.int_value == value)
                    return HASH_ALREADY_ADDED;
                else {
                    p->value.int_value = value;
                    return HASH_REPLACED_VALUE;
                }
            }
            p = p->next;
        }

        HashEntry* node = (HashEntry*)malloc(sizeof(HashEntry));
        if (!node)
            return HASH_ERROR;
        node->key.str_value = (char*)malloc(100);
        if (node->key.str_value == NULL)
            return HASH_ERROR;
        node->key.str_value = (char*)key;
        node->value.int_value = value;
        node->next = table->bucket[keyhash];
        table->bucket[keyhash] = node;

        return HASH_ADDED;
    }
}

void destroy_hash(HashTable* t)
{
    HashEntry *k, *j;

    for(int i = 0; i < t->size; i++)
    {
        k = t->bucket[i];
        while(k != NULL)
        {
            j = k->next;
            free(k->key.str_value);
            free(k);
            k = j;
        }
    }
    free(t->bucket);
    free(t);
}

bool hash_find_int(HashTable *table, const char *key)
{
    long s = hash_string(key);
    HashEntry* k = table->bucket[s];

    while(k != NULL)
    {
        if(!strcmp(k->key.str_value, key))
        {
            printf("%d\n",k->value.int_value);
            return true;
        }

        k = k->next;
    }
    
    printf("false\n");
    return false;
}