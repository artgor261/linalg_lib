#include <stdio.h>

typedef struct{
    int len;
    int *vector;
} vector;

typedef struct{
    int shape[2];
    int **matrix;
} matrix;

void clear_matrix(matrix *matrix);
void fill_matrix(matrix *matrix, int shape[2]);
void print_matrix(matrix matrix);
void fill_vect(vector *vect, int len);
void clear_vect(vector *vect);
void print_vect(vector vect);
void multiple(matrix matrix_1, matrix matrix_2, matrix *result);
void sum(matrix matrix_1, matrix matrix_2, matrix *result);
