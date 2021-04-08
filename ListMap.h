typedef struct ListMap {
    char* key;
    int data;
    struct ListMap* next;
} ListMap;

void ListMap_print(ListMap *h);
ListMap* ListMap_new(char* key, int newData);
void ListMap_insert(ListMap *h, char* key, int newData);
int ListMap_get(ListMap *h, char* key);