#include <stdio.h>
#include <malloc.h>
#include "linalg.h"

void init(int *shape){
    int i;

    for (i=0;i<2;i++){
        printf("Print %d dimension: ", i+1);
        scanf("%d", &shape[i]);
    }
}

int **construct_matrix(int shape[2]){
    int i, j;
    int row = shape[0];
    int col = shape[1];
    int **matrix = (int**)malloc(row*sizeof(int*));
    
    for (i=0;i<row;i++){
        matrix[i] = (int*)malloc(col*sizeof(int));
        for (j=0;j<col;j++){
            printf("Print (%d, %d) matrix value: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    return matrix;
}

void clear(int **matrix, int shape[2]){
    int i, j, row;

    row = shape[0];

    for (i=0;i<row;i++){
        free(matrix[i]);
    }
    free(matrix);
}

void print_matrix(int **matrix, int shape[2]){
    int i, j, row, col;

    row = shape[0];
    col = shape[1];

    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiple(int **matrix_1, int **matrix_2, int **result, int shape_1[2], int shape_2[2]){
    int i, j, z, row_1, col_1, row_2, col_2, element;

    row_1 = shape_1[0];
    col_1 = shape_1[1];
    row_2 = shape_2[0];
    col_2 = shape_2[1];
    element = 0;

    if (col_1==row_2){
        for (i=0;i<row_1;i++){
            result[i] = (int*)malloc(col_2*sizeof(int));
            for (j=0;j<col_2;j++){
                for(z=0;z<col_1;z++){
                    element += matrix_1[i][z] * matrix_2[z][j];
                }
                result[i][j] = element;
                element = 0;
            }
        }
    }
    else{
        printf("Rows and columns does not match");
    }
}

void sum(int **matrix_1, int **matrix_2, int **result, int shape[2]){
    int i, j, row, col;
    
    row = shape[0];
    col = shape[1];
    
    for (i=0;i<row;i++){
        result[i] = (int*)malloc(col*sizeof(int));
        for (j=0;j<col;j++){
            result[i][j] = matrix_1[i][j] + matrix_2[i][j];
        }
    }
}
