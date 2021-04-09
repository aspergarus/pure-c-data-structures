#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "ArrayList.h"

ArrayList* ArrayList_new(int size, int step) {
    ArrayList* arr = (ArrayList*) malloc(sizeof(ArrayList));
    arr->cur = 0;
    arr->len = size;
    arr->data = (int*) malloc(sizeof(int) * arr->len);
    arr->step = step;

    return arr;
}

void ArrayList_print(ArrayList * arr) {
    // printf("Example of dynamic array:\n");
    for (int i = 0; i < arr->cur; i++) {
        printf("%d\n", ArrayList_get(arr, i));
    }
}

int ArrayList_get(ArrayList * arr, int pos) {
    return arr->data[pos];
}

void ArrayList_insert(ArrayList * arr, int newElement) {
    // printf("Adding %d to arr[%d], max len - %d\n", newElement, arr->cur, arr->len);
    if (arr->cur == arr->len) {
        // printf("ArrayList is growing %d\n", arr->len);
        int* tmp = (int*) malloc(sizeof(int) * (arr->len + arr->step));
        memcpy(tmp, arr->data, sizeof(int) * arr->len);
        free(arr->data);
        arr->len += arr->step;
        tmp[arr->cur] = newElement;
        arr->data = tmp;
    } else {
        arr->data[arr->cur] = newElement;
    }
    
    arr->cur++;
}

void ArrayList_insertAll(ArrayList * arr, int num, ...) {
    va_list valist;
    
    va_start(valist, num);
    for (int i = 0; i < num; i++) {
        int newElement = va_arg(valist, int);
        ArrayList_insert(arr, newElement);
    }
    va_end(valist);
}