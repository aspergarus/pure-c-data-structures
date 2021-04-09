typedef struct LinkedListEl {
    int data;
    struct LinkedListEl* next;
} LinkedListEl;

typedef struct LinkedList {
    LinkedListEl* root;
} LinkedList;

LinkedList* LinkedList_new();
int LinkedList_get(LinkedList * list, int pos);
void LinkedList_print(LinkedList *list);
void LinkedList_insert(LinkedList *list, int newData);
void LinkedList_insertAll(LinkedList *list, int num, ...);
