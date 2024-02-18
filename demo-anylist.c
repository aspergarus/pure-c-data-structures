#include <stdio.h>
#include <stdlib.h>
#include "./structures/AnyList.h"

int main() {
    AnyNode* list = createIntNode(42);

    if (list == NULL) {
        printf("Can't create AnyList");
        return 1;
    };

    insertStrList(list, "text");
    insertIntList(list, 45);
    insertStrList(list, "another text");

    printAnyList(list);

    cleanList(list);

    return 0;
}
