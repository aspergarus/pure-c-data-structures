all: compile-list compile-array compile-hashmap compile-treemap

compile-list:
	gcc -o demo-list.exe demo-list.c structures/LinkedList.c

compile-array:
	gcc -o demo-array.exe demo-array.c structures/ArrayList.c

compile-hashmap:
	gcc -o demo-hashmap.exe demo-hashmap.c structures/HashMap.c

compile-treemap:
	gcc -o demo-treemap.exe demo-treemap.c structures/TreeMap.c

list:
	gcc -o demo-list.exe demo-list.c structures/LinkedList.c && ./demo-list.exe

array:
	gcc -o demo-array.exe demo-array.c structures/ArrayList.c && ./demo-array.exe

hash:
	gcc -o demo-hashmap.exe demo-hashmap.c structures/HashMap.c && ./demo-hashmap.exe

tree:
	gcc -o demo-treemap.exe demo-treemap.c structures/TreeMap.c && ./demo-treemap.exe

demo:
	gcc -o demo.exe demo.c structures/LinkedList.c && ./demo.exe	