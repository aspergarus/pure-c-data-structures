#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Any {
    void* value;
    enum {
        INT,
        STRING
    } type;
} Any;

typedef struct AnyNode {
    Any* el;
    struct AnyNode* next;
} AnyNode;

AnyNode* createIntNode(int data) {
    Any* wrapperData = (Any*) malloc(sizeof(Any));
    if (wrapperData == NULL) {
        // Handle allocation failure
        return NULL;
    }

    // Allocate memory and set value for local variable `data`.
    int* intPtr = (int*)malloc(sizeof(int));
    if (intPtr == NULL) {
        // Handle allocation failure
        free(wrapperData);
        return NULL;
    }
    *intPtr = data;

    wrapperData->value = intPtr;
    wrapperData->type = INT;

    AnyNode* node = (AnyNode*) malloc(sizeof(AnyNode));
    if (node == NULL) {
        // Handle allocation failure
        free(intPtr);
        free(wrapperData);
        return NULL;
    }

    node->next = NULL;
    node->el = wrapperData;
    return node;
}

AnyNode* createStrNode(char data[]) {
    Any* wrapperData = (Any*) malloc(sizeof(Any));
    if (wrapperData == NULL) {
        // Handle allocation failure
        return NULL;
    }

    // Allocate memory and set value for local variable `data`.
    char* strPtr = (char*)malloc(strlen(data) + 1);
    if (strPtr == NULL) {
        // Handle allocation failure
        free(wrapperData);
        return NULL;
    }
    strcpy(strPtr, data); // Copy the content of data to strPtr

    wrapperData->value = strPtr;
    wrapperData->type = STRING;

    AnyNode* node = (AnyNode*) malloc(sizeof(AnyNode));
    if (node == NULL) {
        // Handle allocation failure
        free(strPtr);
        free(wrapperData);
        return NULL;
    }

    node->next = NULL;
    node->el = wrapperData;
    return node;
}

void printAnyList(AnyNode* list) {
    AnyNode* tmpList = list;
    int count = 0;

    while(tmpList != NULL) {
        Any* wrappedData = tmpList->el;

        if (wrappedData->type == INT) {
            printf("Item[%d,INT] = %d\n", count++, *(int*)wrappedData->value);
        } else if (wrappedData->type == STRING) {
            printf("Item[%d,STR] = %s\n", count++, (char*)wrappedData->value);
        } else {
            perror("Unknown type of element");
        }

        tmpList = tmpList->next;
    }
}

void insertIntList(AnyNode* list, int data) {
    AnyNode* tmpList = list;

    while(tmpList->next != NULL) {
        tmpList = tmpList->next; 
    }

    AnyNode* newNode = createIntNode(data);
    tmpList->next = newNode;
}

void insertStrList(AnyNode* list, char data[]) {
    AnyNode* tmpList = list;

    while(tmpList->next != NULL) {
        tmpList = tmpList->next; 
    }

    AnyNode* newNode = createStrNode(data);
    tmpList->next = newNode;
}

void cleanList(AnyNode* list) {
    AnyNode* current = list;
    
    while(current != NULL) {
        AnyNode* temp = current;
        current = current->next;

        free(temp->el->value);
        free(temp->el);
        free(temp); 
    }
}