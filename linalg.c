#include <stdio.h>
#include "linalg.h"

void fill_matrix(matrix *matrix, int shape[2]){
    int row, col, i, j;

    memcpy(matrix->shape, shape, sizeof(matrix->shape));
    row = matrix->shape[0];
    col = matrix->shape[1];
    matrix->matrix = (int**)malloc(row*sizeof(int*));

    for (i=0;i<row;i++){
        matrix->matrix[i] = (int*)malloc(col*sizeof(int));
        for (j=0;j<col;j++){
            printf("Print (%d %d) value: ", i, j);
            scanf("%d", &matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

void clear_matrix(matrix *matrix){
    int row, i;

    row = matrix->shape[0];

    for (i=0;i<row;i++){
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
}

void print_matrix(matrix matrix){
    int i, j, row, col;

    row = matrix.shape[0];
    col = matrix.shape[1];

    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            printf("%d ", matrix.matrix[i][j]);
        }
        printf("\n");
    }
}

void fill_vect(vector *vector, int len){
    int i;

    vector->len = len;
    vector->vector = (int*)malloc(len*sizeof(int));

    for (i=0;i<len;i++){
        printf("Print %d element: ", i);
        scanf("%d", &vector->vector[i]);
    }
}

void clear_vect(vector *vector){
    vector->len = 0;
    free(vector->vector);
}

void print_vect(vector vect){
    int i;
    int len = vect.len;

    for (i=0;i<len;i++){
        printf("%d ", vect.vector[i]);
    }
}

void multiple(matrix matrix_1, matrix matrix_2, matrix *result){
    int i, j, z, row_1, col_1, row_2, col_2, element;

    row_1 = matrix_1.shape[0];
    col_1 = matrix_1.shape[1];
    row_2 = matrix_2.shape[0];
    col_2 = matrix_2.shape[1];
    memcpy(result->shape, matrix_2.shape, sizeof(result->shape));
    result->matrix = (int**)malloc(row_2*sizeof(int*));
    element = 0;

    if (col_1==row_2){
        for (i=0;i<row_1;i++){
            result->matrix[i] = (int*)malloc(col_2*sizeof(int));
            for (j=0;j<col_2;j++){
                for(z=0;z<col_1;z++){
                    element += matrix_1.matrix[i][z] * matrix_2.matrix[z][j];
                }
                result->matrix[i][j] = element;
                element = 0;
            }
        }
    }
    else{
        printf("Rows and columns does not match");
    }
}

void sum(matrix matrix_1, matrix matrix_2, matrix *result){
    int i, j, row, col;
    
    row = matrix_1.shape[0];
    col = matrix_1.shape[1];
    memcpy(result->shape, matrix_1.shape, sizeof(result->shape));
    result->matrix = (int**)malloc(row*sizeof(int*));
    
    for (i=0;i<row;i++){
        result->matrix[i] = (int*)malloc(col*sizeof(int));
        for (j=0;j<col;j++){
            result->matrix[i][j] = matrix_1.matrix[i][j] + matrix_2.matrix[i][j];
        }
    }
}
