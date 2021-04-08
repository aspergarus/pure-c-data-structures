#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ListMap.h"

void ListMap_print(ListMap *h) {
    while(h != NULL) {
        printf("[%s] = %d\n", h->key, h->data);
        h = h->next;
    }
}

ListMap* ListMap_new(char* key, int newData) {
    ListMap *newVal = (ListMap*) malloc(sizeof(ListMap));
    newVal->key = key;
    newVal->data = newData;
    newVal->next = NULL;
}

void ListMap_insert(ListMap *h, char* key, int newData) {
    while(h->next != NULL) {
        h = h->next;
    }
    ListMap *newVal = ListMap_new(key, newData);

    h->next = newVal;
}

int ListMap_get(ListMap *h, char* key) {
    while(h->next != NULL) {
        if (strcmp(h->key, key) == 0) {
            return h->data;
        }
        h = h->next;
    }

    return 0;
}
