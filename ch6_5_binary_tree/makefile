compare_string.o: compare_string.c
	gcc -c compare_string.c
copy_string.o: copy_string.c
	gcc -c copy_string.c
create_node.o: create_node.c
	gcc -c create_node.c
inorder_print.o: inorder_print.c
	gcc -c inorder_print.c
free_postorderly.o: free_postorderly.c
	gcc -c free_postorderly.c
test: compare_string.o copy_string.o create_node.o inorder_print.o
	gcc test.c compare_string.o copy_string.o create_node.o inorder_print.o -o test
main.o: main.c
	gcc -c main.c
main: main.o compare_string.o copy_string.o create_node.o inorder_print.o free_postorderly.o
	gcc main.o compare_string.o copy_string.o create_node.o inorder_print.o free_postorderly.o -o main
