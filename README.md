# linalg_lib

This is the open-source library for linear algebra operations with user-friendly API. It includes more different functions for quickly and effective scientific and engeneering computations with base linear algebra objects such as `vector` and `matrix`.

## Usage

### Quick Start

There are two main objects: `vector` and `matrix`. To create it use the following syntax:

```
matrix mrx;
vector vect;
```

You can get access to its fields by:

```
mrx.shape
mrx.matrix

vect.len
vect.vector
```

This structures are empty. To fill it use `fill_matrix()` and `fill_vect` functions:

```
// matrix shape
int shape[2] = {2, 2};

// vector length
int len = 5;

// filling
fill_matrix(&mrx, shape);
fill_vect(&vect, len);

// don't forget clearing created structures after using 
clear_matrix(&mrx);
clear_vect(%vect);
```

First of all you should to initialize matrix shape and vector lenght. Then you invokes two functions for filling your structures which requires two parameters: `pointer` on matrix/vector and shape/length. Note that you have to send **pointer** on structure, but not structure. And don't forget clearing structures after its using. If you don't do this, you can spent a big amount of memory.

You have created your structures, you filled it. May be you want to print them? To do this invokes `print_matrix()` and `print_vect()` functions:

```
printf("\nMatrix: \n");
print_matrix(mrx);

printf("\nVector: ");
print_vect(vect);
```

Paste the code above between filling and clearing code strings.

Great. Let's try something more difficult. If you want to multiply two matrices use `multiply()` function:

```
// initializing shapes
int shape_1[2] = {2, 2};
int shape_2[2] = {2, 2};

// creates a third object which stores result of multiply
matrix mrx_1, mrx_2, result;

// filling matrices
fill_matrix(&mrx_1, shape_1);
fill_matrix(&mrx_2, shape_2);

// printing matrices
printf("\nFirst matrix: \n");
print_matrix(mrx_1);
printf("\nSecond matrix: \n");
print_matrix(mrx_2);

// multiply and printing result
multiply(mrx_1, mrx_2, &result);
printf("\nResult matrix: \n");
print_matrix(result);

// clearing 
clear_matrix(&mrx_1);
clear_matrix(&mrx_2);
clear_matrix(&result);
```

`multiply()` function multiply two matrices and save result into result matrix. Note that **result** parameter should be a **pointer** on structure and two matrices should be structures. And don't forget that `mrx_1.shape[1] = mrx_2.shape[0]` i.e. columns count of first matrix should be equal to rows count of second matrix.

If you want to sum two matrices use `sum()` function:

```
int shape[2] = {3, 3};
matrix mrx_1, mrx_2, result;

// matrices should be one shape when sum
fill_matrix(&mrx_1, shape);
fill_matrix(&mrx_2, shape);

// sum two matrices and save result
sum(mrx_1, mrx_2, &result);

// print result
print_matrix(result);

// clearing
clear(&mrx_1);
clear(&mrx_2);
clear(&result);

```






