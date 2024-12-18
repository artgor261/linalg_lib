#include <stdio.h>

int **construct_matrix(int shape[2]);
void clear(int **matrix, int shape[2]);
void print_matrix(int **matrix, int shape[2]);
void multiple(int **matrix_1, int **matrix_2, int **result, int shape_1[2], int shape_2[2]);
void init(int *shape); 
void sum(int **matrix_1, int **matrix_2, int **result, int shape[2]);
