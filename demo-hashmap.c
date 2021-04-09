#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "./structures/HashMap.h"

void demo();
void printMapEl(HashMap* map, char* key);

int main()
{
	printf("HashMap demo\n");
    demo();

    printf("Press enter button to proceed");
    getchar();

    return 0;
}

void demo() {
	HashMap* map = HashMap_new(300);
	char* newKey;

	for (int i = 1000; i < 10000; i++) {
		newKey = (char*) malloc(255);
		sprintf(newKey, "test-%d", i);
		HashMap_insert(map, newKey, i + 5);
		printMapEl(map, newKey);
	}
}

void printMapEl(HashMap* map, char* key) {
	printf("map[%s] = %d\n", key, HashMap_get(map, key));
}

