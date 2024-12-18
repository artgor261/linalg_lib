# linalg_lib

This project consists of three files:

1. `linalg.h` - header file which stores functions signatures
2. `linalg.c` - `.c` file which includes functions implementations
3. `main.c` - executable file which demonstrates library API


# Usage

## construct_matrix

**Signature:** `int **construct_matrix(int shape[2]);`

This function creates a matrix based on `shape` parameter. `malloc` invoked within body. `construct_matrix` returns a two-dimensional array (matrix) like pointer on pointer.

**Example:**

```
int shape[2] = {3, 2};
int **matrix = construct_matrix(shape);
```

## init

**Signature:** `void init(int *shape);`

Initialize a shape of matrix.

**Example:**

```
int shape[2];
init(shape);
```

## print_matrix

**Signature:** `void print_matrix(int **matrix, int shape[2]);`

Printing matrix into `stdout`.

**Example:**

```
int shape[2] = {3, 2};
int matrix[3][2] = {{2, 1}, {3, 4}, {7, 2}};
print_matrix(matrix, shape);
```

## clear

**Signature:** `void clear(int **matrix, int shape[2]);`

Clearing allocated memory used for storing matrix.

**Example:**

```
int i, j;
int shape[2] = {2, 2};
int **matrix = (int **)malloc(shape[0]*sizeof(int *)));

// filling matrix
for (i=0;i<shape[0];i++){
     matrix[i] = (int *)malloc(shape[1]*sizeof(int));
     for (j=0;j<shape[1];j++){
          matrix[i][j] = i*j;
     }
}

// printing matrix
print_matrix(matrix, shape);

// clearing allocated memory
clear(matrix, shape);
```

## multiple

**Signature:** `void multiple(int **matrix_1, int **matrix_2, int **result, int shape_1[2], int shape_2[2]);`

Multiple two matrix.

**Example:**

```
int shape_1[2] = {2, 3};
int shape_2[2] = {3, 2};
int **matrix_1;
int **matrix_2;
int **result;

matrix_1 = construct_matrix(shape_1);
matrix_2 = constract_matrix(shape_2);
result = (int **)malloc(shape_2[0]*sizeof(int *));

multiple(matrix_1, matrix_2, result, shape_1, shape_2);
print_matrix(result, shape_2);

clear(matrix_1);
clear(matrix_2);
clear(result);
```

## sum

**Signature:** `void sum(int **matrix_1, int **matrix_2, int **result, int shape[2]);`

Sum two matrix.

**Example:**

```
int shape[2] = {2, 2};
int **matrix_1 = construct_matrix(shape);
int **matrix_2 = construct_matrix(shape);
int **result = (int **)malloc(shape[0]*sizeof(int *));

sum(matrix_1, matrix_2, result, shape);
print_matrix(result, shape);

clear(matrix_1);
clear(matrix_2);
clear(result);
```

