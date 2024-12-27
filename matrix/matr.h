#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    short lW;
    short lK;
    double data[];
} Matrix2D;

Matrix2D* multiply_matrices(Matrix2D*, Matrix2D*);
double dot_product(Matrix2D*, Matrix2D*);
void transpose(Matrix2D*);
Matrix2D* copy_matrix(Matrix2D*);