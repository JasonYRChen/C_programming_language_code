error.o: error.c
	gcc -c error.c
file_compare.o: file_compare.c
	gcc -c file_compare.c
main.o: main.c
	gcc -c main.c
main: error.o file_compare.o main.o
	gcc error.o file_compare.o main.o -o main
