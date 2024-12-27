#include "matr.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


Matrix2D* multiply_matrices(Matrix2D* mac1, Matrix2D* mac2) {
    if (mac1 == NULL || mac2 == NULL || mac1->lK != mac2->lW) {
        return NULL; // cannot multiply
    }

    if (mac1->lW <= 0 || mac1->lK <= 0 || mac2->lW <= 0 || mac2->lK <= 0) {
        return NULL;
    }

    Matrix2D* result = malloc(sizeof(Matrix2D) + mac1->lW * mac2->lK * sizeof(double));  // memory allocation for result matrix
    if (result == NULL) {
        return NULL; // memory allocation error
    }


    result->lW = mac1->lW;  // result number of rows
    result->lK = mac2->lK;  // result number of columns

    for (int i = 0; i < mac1->lW; i++) {
        for (int j = 0; j < mac2->lK; j++) {
            double suma = 0;
            for (int k = 0; k < mac1->lK; k++) {
                suma += mac1->data[i * mac1->lK + k] * mac2->data[k * mac2->lK + j];
            }
            result->data[i * mac2->lK + j] = suma;
        }
    }

    return result;
}




double dot_product(Matrix2D* mac1, Matrix2D* mac2) {
    if (mac1 == NULL || mac2 == NULL || (mac1->lW != 1 && mac1->lK != 1) || (mac2->lW != 1 && mac2->lK != 1)) {
        return NAN;
    }

    if (mac1->lW <= 0 || mac1->lK <= 0 || mac2->lW <= 0 || mac2->lK <= 0) {
        return NAN;
    }

    double result = 0;
    for (int i = 0; i < mac1->lW * mac1->lK; i++) {
        result += mac1->data[i] * mac2->data[i];
    }

    return result;
}





void transpose(Matrix2D* mat) {
    if (mat == NULL) {
        return;
    }
    if (mat->lW <= 0 || mat->lK <= 0) {
        fprintf(stderr, "Error (invalid matrix dimensions)\n");
        return;
    }
    Matrix2D* temp = malloc(sizeof(Matrix2D) + mat->lK * mat->lW * sizeof(double));

    if (temp == NULL) {
        return;
    }

    temp->lW = mat->lK;
    temp->lK = mat->lW;

    for (int i = 0; i < mat->lW; i++) {
        for (int j = 0; j < mat->lK; j++) {
            temp->data[j * temp->lK + i] = mat->data[i * mat->lK + j];
        }
    }


    memcpy(mat, temp, sizeof(Matrix2D) + mat->lW * mat->lK * sizeof(double));
    mat->lW = temp->lW;
    mat->lK = temp->lK;
    free(temp);
}





Matrix2D* copy_matrix(Matrix2D* mac) {
    if (mac == NULL) {
        return NULL;
    }


    Matrix2D* kopia = malloc(sizeof(Matrix2D) + mac->lW * mac->lK * sizeof(double));  // memory allocation for matrix copy
    if (!kopia) {
        return NULL; // memory allocation error
    }

    kopia->lW = mac->lW;
    kopia->lK = mac->lK;
    for (int i = 0; i < mac->lW * mac->lK; i++) {
        kopia->data[i] = mac->data[i];
    }

    return kopia;
}
