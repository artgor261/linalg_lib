# linalg_lib

This project consists of three files:

1. `linalg.h` - header file which stores functions signatures
2. `linalg.c` - `.c` file which includes functions implementations
3. `main.c` - executable file which demonstrates library API


## Usage

### construct_matrix

**Signature:** `int **construct_matrix(int shape[2]);`

This function creates a matrix based on its shape. The matrix memory allocated within it. `construct_matrix` returns two-dimensional array like pointer on pointer.

**Example**

```
int shape[2] = {3, 2};
int **matrix = construct_matrix(shape);
```

### init

**Signature:** `void init(int *shape);`

Initialize a shape of matrix.

**Example**

```
int shape[2];
init(shape);
```

### print_matrix

**Signature:** `void print_matrix(int **matrix, int shape[2]);`

Printing matrix into `stdout`.

**Example**

```
int shape[2] = {3, 2};
int matrix[3][2] = {{2, 1}, {3, 4}, {7, 2}};
print_matrix(matrix, shape);
```


