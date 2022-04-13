hashit.o: hashit.c
	gcc -c hashit.c
string_compare.o: string_compare.c
	gcc -c string_compare.c
table_implement.o: table_implement.c
	gcc -c table_implement.c
main.o: main.c
	gcc -c main.c
error.o: error.c
	gcc -c error.c
main: hashit.o string_compare.o table_implement.o main.o error.o
	gcc hashit.o string_compare.o table_implement.o main.o error.o -o main
