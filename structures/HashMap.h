#include <stddef.h>

typedef struct HashMapEl {
    char* key;
    int data;
    struct HashMapEl* next;
} HashMapEl;

typedef struct HashMap {
    HashMapEl** list;
    int size;
} HashMap;

HashMap* HashMap_new(int size);
int HashMap_hash(char* key, int mapLimit);
void HashMap_insert(HashMap* map, char* key, int value);
int HashMap_get(HashMap* map, char* key);
