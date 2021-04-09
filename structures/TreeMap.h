#include <stddef.h>

typedef struct TreeMapEl {
    char* key;
    int data;
    struct TreeMapEl* left;
    struct TreeMapEl* right;
} TreeMapEl;

typedef struct TreeMap {
    TreeMapEl* root;
} TreeMap;

TreeMap* TreeMap_new();
void TreeMap_insert(TreeMap* map, char* key, int value);
int TreeMap_get(TreeMap* map, char* key);
