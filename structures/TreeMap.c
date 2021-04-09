#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "TreeMap.h"

TreeMap* TreeMap_new(int size) {
	TreeMap* map = (TreeMap*) malloc(sizeof(TreeMap));
	map->root = NULL;
	return map;
}

void TreeMap_insert(TreeMap* map, char* key, int value) {
	TreeMapEl* el = (TreeMapEl*) malloc(sizeof(TreeMapEl));
	TreeMapEl* cur;
	el->left = NULL;
	el->right = NULL;
	el->key = key;
	el->data = value;

	if (map->root == NULL) {
		map->root = el;
		return;
	}

	cur = map->root;

	while(1) {
		int res = strcmp(cur->key, key);
		if (res < 0) {
			if (cur->left == NULL) {
				cur->left = el;
				return;
			} else {
				cur = cur->left;
			}
		} else {
			if (cur->right == NULL) {
				cur->right = el;
				return;
			} else {
				cur = cur->right;
			}
		}
	}
}

int TreeMap_get(TreeMap* map, char* key) {
	TreeMapEl* cur = map->root;

	while(1) {
		int res = strcmp(cur->key, key);
		if (res < 0) {
			if (cur->left == NULL) {
				return 0;
			} else {
				cur = cur->left;
			}
		} else if (res > 0) {
			if (cur->right == NULL) {
				return 0;
			} else {
				cur = cur->right;
			}
		} else {
			return cur->data;
		}
	}
}
