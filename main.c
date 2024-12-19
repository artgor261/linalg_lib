#include <stdio.h>
#include <malloc.h>
#include "linalg.c"

int main(void){
    // var 'i' stores the second char from stdin
    int ch, i;

    printf("Print command(press 'Ctrl+C' if you want to exit: ");
    while ( (ch=getchar()) != EOF){
        // we can validate an input by that
        i = getchar();
        if (ch=='+' && i=='\n'){
            int shape[2]; // matrices shoud be one shape when sum 
            int **matrix_1;
            int **matrix_2;
            int **result;

            init(shape);
            result = (int**)malloc(shape[0]*sizeof(int*));
            matrix_1 = construct_matrix(shape);
            matrix_2 = construct_matrix(shape);
            
            sum(matrix_1, matrix_2, result, shape);
            print_matrix(result, shape);
            
            // clearing allocated memory
            clear(result, shape);
            clear(matrix_1, shape);
            clear(matrix_2, shape);
        }
        else if (ch=='*' && i=='\n'){
            // note that shape_1[1] = shape_2[0]
            int shape_1[2];
            int shape_2[2];
            int **matrix_1;
            int **matrix_2;
            int **result;

            init(shape_1);
            init(shape_2);
            
            // shape of result matrix = shape_2
            result = (int**)malloc(shape_2[0]*sizeof(int*));
            
            matrix_1 = construct_matrix(shape_1);
            matrix_2 = construct_matrix(shape_2);
            
            multiple(matrix_1, matrix_2, result, shape_1, shape_2);
            print_matrix(result, shape_2);

            // clearing allocated memory
            clear(matrix_1, shape_1);
            clear(matrix_2, shape_2);
            clear(result, shape_2); 
        }
        else{
            printf("Incorrent command\n");
        }
        // clearing stdin
        while ( (ch=getchar()) != EOF && ch != '\n'){ }
        printf("Print command(print 'Ctrl+C' if you want to exit: ");
    }
    // finally clearing stdin just in case
    while ( (ch=getchar()) != EOF && ch != '\n'){ }

    return 0;
}
