bisearch.o: bisearch.c
	gcc -c bisearch.c
case_convert.o: case_convert.c
	gcc -c case_convert.c
count_stat.o: count_stat.c
	gcc -c count_stat.c
error.o: error.c
	gcc -c error.c
main.o: main.c
	gcc -c main.c
main: main.o bisearch.o case_convert.o count_stat.o error.o
	gcc main.o bisearch.o case_convert.o count_stat.o error.o -o main 
