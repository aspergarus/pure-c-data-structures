#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "./structures/TreeMap.h"

void treeMapDemo();
void printMapEl(TreeMap* map, char* key);

int TEST_SIZE = 10000;

int main()
{
	printf("TreeMap demo\n");
    treeMapDemo();

    printf("Press enter button to proceed");
    getchar();

    return 0;
}

void treeMapDemo() {
	TreeMap* map = TreeMap_new();
	char* newKey;

	for (int i = 1; i < TEST_SIZE; i++) {
		newKey = (char*) malloc(255);
		sprintf(newKey, "test-%d", i);
		TreeMap_insert(map, newKey, i + 5);
		printMapEl(map, newKey);
	}
}

void printMapEl(TreeMap* map, char* key) {
	printf("map[%s] = %d\n", key, TreeMap_get(map, key));
}

