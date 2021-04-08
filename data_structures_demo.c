#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "ListMap.h"
#include "HashMap.h"
#include "ArrayList.h"
#include "LinkedList.h"


void linkedListDemo();
void arrayListDemo();
void listMapDemo();
void hashMapDemo();

int TEST_SIZE = 100000;

int main()
{
    linkedListDemo();
    arrayListDemo();
    listMapDemo();
    hashMapDemo();

    printf("Press enter button to proceed");
    getchar();

    return 0;
}

void linkedListDemo() {
    printf("LinkedList demo:\n");

    LinkedList* list = LinkedList_new();
    for (int i = 0; i < TEST_SIZE; i++) {
        LinkedList_insert(list, i + 100);
    }
    // LinkedList_insert(list, 1);
    // LinkedList_insert(list, 3);
    // LinkedList_insert(list, 6);
    // LinkedList_insertAll(list, 3, 7, 8, 9);
    printf("list[%d] = |%d|\n", 505, LinkedList_get(list, 505));
    // LinkedList_print(list);

    printf("***\n");
}

void arrayListDemo() {
    printf("ArrayList demo:\n");

    ArrayList* arr = ArrayList_new(10, 10);

    for (int i = 0; i < TEST_SIZE; i++) {
        ArrayList_insert(arr, i + 100);
    }

    printf("arr[%d] = |%d|\n", 505, ArrayList_get(arr, 505));
    // ArrayList_insertAll(arr, 5, 1,2,3,4,5);
    // ArrayList_print(arr);

    printf("***\n");
}

void listMapDemo() {
    printf("ListMap demo:\n");

    ListMap* map = ListMap_new("test", 555);
    char* key;
    int charSize = 4;

    for (int i = 0; i < 1000; i++) {
        key = (char*) malloc(sizeof(char) * charSize);
        sprintf(key, "%d", i);
        ListMap_insert(map, key, i + 100);
    }

    // ListMap_insert(map, "my_own_key_for_hash", 123);
    // ListMap_print(map);
    printf("map['%s'] = %d\n", "505", ListMap_get(map, "505"));

    printf("***\n");
}

void hashMapDemo() {
    printf("Hashmap demo:\n");

    HashMap* map = HashMap_new(30);
    char* key;
    int charSize = 4;

    for (int i = 0; i < TEST_SIZE; i++) {
        key = (char*) malloc(sizeof(char) * charSize);

        // printf("before create key\n");

        sprintf(key, "%d", i);
        // printf("key = '%s'\n", key);
        HashMap_insert(map, key, i + 100, charSize);
    }
    printf("map['%s'] = %d\n", "500", HashMap_get(map, "500", charSize));


    printf("***\n");
}
