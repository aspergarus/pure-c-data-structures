#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "./structures/ArrayList.h"

int TEST_SIZE = 10000;

void demo();
void printArrayEl(ArrayList* arr, int key);

int main()
{
    demo();

    printf("Press enter button to proceed");
    getchar();

    return 0;
}

void demo() {
    printf("ArrayList demo:\n");

    ArrayList* arr = ArrayList_new(256, 1024);

    for (int i = 0; i < TEST_SIZE; i++) {
        ArrayList_insert(arr, i + 100);
        printArrayEl(arr, i);
    }

    printf("***\n");
}

void printArrayEl(ArrayList* arr, int key) {
	printf("arr[%d] = |%d|\n", key, ArrayList_get(arr, key));
}
