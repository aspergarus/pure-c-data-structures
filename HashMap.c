#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "HashMap.h"

HashMap* HashMap_new(int size) {
    HashMap *map = (HashMap*) malloc(sizeof(HashMap));
    map->size = size;
    map->list = (HashMapEl**) malloc(sizeof(HashMapEl*) * size);

    for (int i = 0; i < size; i++) {
        map->list[i] = NULL;
    }

    return map;
}

int HashMap_hash(char* key, int size, int mapLimit) {
    char c = key[0];
    int breakLimit = 100;
    int i = 0;
    int res = 0;

    for (int i = 0; i < size; i++) {
        // printf("str[%d] = %c, %d\n", i, c, res);

        if (i >= breakLimit) {
            break;
        }
        // c = key[i] - '0';
        c = key[i];
        res += c;
    }

    return res % mapLimit;
}

void HashMap_insert(HashMap* map, char* key, int value, int size) {
    // printf("HashMap_insert, key = %s, data = %d\n", key, value);
    int hashedKey = HashMap_hash(key, size, map->size);
    // printf("hashedKey = %d\n", hashedKey);

    HashMapEl* el = (HashMapEl*) malloc(sizeof(HashMapEl));
    el->key = key;
    el->data = value;
    el->next = NULL;

    if (map->list[hashedKey] == NULL) {
        map->list[hashedKey] = el;
    } else {
        HashMapEl* current = map->list[hashedKey];

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = el;
    }
}

int HashMap_get(HashMap* map, char* key, int size) {
    int hashedKey = HashMap_hash(key, size, map->size);

    HashMapEl* current = map->list[hashedKey];

    do {
        if (strcmp(key, current->key) == 0) {
            return current->data;
        }

        current = current->next;
    } while (current != NULL);

    return 0;
}
