/*
    The process sequence should be:
    1. Initialize bitmap: use 'initialize_bitmap' to do so. It sets all zeros in
       bitmap and validate col dimension, which should be less than an integer could
       save.
    2. Use user interface to plot the graph: use 'command' to set or reset pixel.
       The commands in sequence have three parts: command, row number, and col number.
       The first part accept three charactor s, r, and q, each representing set pixel, 
       reset pixel, and quit.
    3. Set designated pixel to 1: use 'set_pixel' to do so.
    4. Reset pixel from last step: use 'reset_pixel'.
    5. Show the graph with customized charactors: use 'show_graph' and replace '1' in
       bitmap with parameter 'one' and '0' with parameter 'zero', which are all charactors 

    General use parameter names
    1. bitmap (int []): an integer array saves 0 and 1 to indicate a binary graph. 
       Each integer is regarded as a binary number and a row, where each bit in a integer 
       represents a pixel and the column.
    2. len_bitmap (int): the length of the bitmap, also the rows of the bitmap.
    3. bits (int): the effective bits in an integer, also the columns of the bitmap.
*/

#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"
#include <limits.h>

int int_limit()
{
    int i;
    int max = INT_MAX;
    for (i = 0; max; i++, max >>= 1)
        ;
    return i;
}

void initialize_bitmap(int *bitmap, int len_bitmap, int bits)
{
    if (bits > int_limit())
        error("Invalid bit number\n");
    while (len_bitmap)
        bitmap[--len_bitmap] = 0;
}

void set_pixel(int *bitmap, int len_bitmap, int bits, int row, int col)
{
    if (row < 0 || row >= len_bitmap || col < 0 || col >= bits)
        error("Invalid coordinates\n");
    bitmap[row] |= (1 << (bits - 1 - col));
}

void reset_pixel(int *bitmap, int len_bitmap, int bits, int row, int col)
{
    if (row < 0 || row >= len_bitmap || col < 0 || col >= bits)
        error("Invalid coordinates\n");

    int probe, i;
    for (i = 0, probe = 0; i < bits; i++)
        probe = (probe << 1) + 1;
    bitmap[row] &= (probe ^ (1 << (bits - 1 - col)));
}

void show_graph(int *bitmap, int len_bitmap, int bits, char one, char zero)
{
    int probe, i;
    
    for (i = 0; i < len_bitmap; i++) {
        probe = (1 << (bits - 1));
        for (; probe; probe >>= 1)
            (bitmap[i] & probe)? printf("%c", one): printf("%c", zero);
        printf("\n");
    }
}

void command(int *bitmap, int len_bitmap, int bits)
{
    int row, col;
    int flag_stop = 0;
    char cmd[100];
    char action;

    while (!flag_stop) {
        printf("Enter command (format: s/r/q row col): ");
        fgets(cmd, sizeof(cmd), stdin);
        sscanf(cmd, "%c %i %i", &action, &row, &col);
        switch (action) {
            default:
                printf("Unknown command. Ready to quit\n");
            case 'q':
            case 'Q':
                flag_stop = 1;
                break;
            case 's':
                set_pixel(bitmap, len_bitmap, bits, row, col);
                break;
            case 'r':
                reset_pixel(bitmap, len_bitmap, bits, row, col);
                break;
        }
        show_graph(bitmap, len_bitmap, bits, 'x', ' ');
    }
}

