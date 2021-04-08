#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "LinkedList.h"

LinkedList* LinkedList_new() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->root = NULL;
    return list;
}

int LinkedList_get(LinkedList * list, int pos) {
    int curPos = 0;
    LinkedListEl* curEl = list->root;
    while(curEl != NULL && curPos < pos) {
        curPos++;
        curEl = curEl->next;
    }

    return curEl->data;
}

void LinkedList_print(LinkedList *list) {
    LinkedListEl* curEl = list->root;
    while(curEl != NULL) {
        printf("%d\n", curEl->data);
        curEl = curEl->next;
    }
}

void LinkedList_insert(LinkedList *list, int newData) {
    LinkedListEl *newElement = (LinkedListEl*) malloc(sizeof(LinkedListEl));
    newElement->data = newData;
    newElement->next = NULL;

    if (list->root == NULL) {
        list->root = newElement;
        return;
    }

    LinkedListEl* curEl = list->root;
    while(curEl->next != NULL) {
        curEl = curEl->next;
    }

    curEl->next = newElement;
}

void LinkedList_insertAll(LinkedList *list, int num, ...) {
    va_list valist;

    va_start(valist, num);

    for (int i = 0; i < num; i++) {
        LinkedList_insert(list, va_arg(valist, int));
    }
    
    va_end(valist);
}
