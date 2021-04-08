all: compile run

compile:
	gcc -o data_structures_demo.exe data_structures_demo.c HashMap.c ListMap.c ArrayList.c LinkedList.c

run:
	./data_structures_demo.exe
