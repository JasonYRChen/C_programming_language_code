build_bitmap.o: build_bitmap.c
	gcc -c build_bitmap.c
error.o: error.c
	gcc -c error.c
main.o: main.c
	gcc -c main.c
main: main.o build_bitmap.o error.o
	gcc main.o build_bitmap.o error.o -o main
