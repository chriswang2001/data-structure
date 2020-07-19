#include "hash.h"
#include <stdio.h>

int main()
{
    HashTable* t = create_hash(7);
    char* s = "uuu4uuu4";
    hash_add_int(t, s, 93);
    hash_add_int(t, s, 1861);
    destroy_hash(t);

    return 0;
}