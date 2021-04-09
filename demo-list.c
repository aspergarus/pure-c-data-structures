#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "./structures/LinkedList.h"

void linkedListDemo();
void printListEl(LinkedList* arr, int key);

int TEST_SIZE = 10000;

int main()
{
    linkedListDemo();

    printf("Press enter button to proceed");
    getchar();

    return 0;
}

void linkedListDemo() {
    printf("LinkedList demo:\n");

    LinkedList* list = LinkedList_new();
    for (int i = 0; i < TEST_SIZE; i++) {
        LinkedList_insert(list, i + 100);
        printListEl(list, i);
    }

    printf("***\n");
}

void printListEl(LinkedList* arr, int key) {
    printf("arr[%d] = |%d|\n", key, LinkedList_get(arr, key));
}
