quick_sort.o: quick_sort.c
	gcc -c quick_sort.c
main.o: main.c
	gcc -c main.c
error.o: error.c
	gcc -c error.c
main: quick_sort.o main.o error.o
	gcc quick_sort.o main.o error.o -o main
cr: quick_sort.o main.o error.o
	gcc quick_sort.o main.o error.o -o main && ./main
