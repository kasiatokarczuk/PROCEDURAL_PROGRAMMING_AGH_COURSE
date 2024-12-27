#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "matr.h"


int main() {
    // Example matrices
    Matrix2D* m1 = malloc(sizeof(Matrix2D) + sizeof(double) * 2 * 3);  //first matrix
    if (m1 == NULL) {
        return NULL;
    }
    m1->lW = 2;
    m1->lK = 3;
    m1->data[0] = 1; m1->data[1] = 2; m1->data[2] = 3;
    m1->data[3] = 4; m1->data[4] = 5; m1->data[5] = 6;




    Matrix2D* m2 = malloc(sizeof(Matrix2D) + sizeof(double) * 3 * 2);  //second matrix
    if (m2 == NULL) {
        return NULL;
    }
    m2->lW = 3;
    m2->lK = 2;
    m2->data[0] = 2; m2->data[1] = 3;
    m2->data[2] = 4; m2->data[3] = 5;
    m2->data[4] = 6; m2->data[5] = 7;


    // Printing the first matrix
    printf("First matrix:\n");
    for (int i = 0; i < m1->lW; i++) {
        for (int j = 0; j < m1->lK; j++) {
            printf("%lf ", m1->data[i * m1->lK + j]);
        }
        printf("\n");
    }


    // Printing the second matrix
    printf("Second matrix:\n");
    for (int i = 0; i < m2->lW; i++) {
        for (int j = 0; j < m2->lK; j++) {
            printf("%lf ", m2->data[i * m2->lK + j]);
        }
        printf("\n");
    }



    // Example of matrix multiplication
    Matrix2D* result = multiply_matrices(m1, m2);
    if (result) {
        printf("Result of matrix multiplication:\n");
        for (int i = 0; i < result->lW; i++) {
            for (int j = 0; j < result->lK; j++) {
                printf("%lf ", result->data[i * result->lK + j]);
            }
            printf("\n");
        }
        free(result);
    }
    else {
        printf("Error(invalid matrix dimensions)\n");
    }

    printf("\n");


    // Example vector (third matrix)
    Matrix2D* m3 = malloc(sizeof(Matrix2D) + 1 * 4 * sizeof(double));
    if (m3 == NULL) {
        return NULL;
    }
    m3->lW = 1;
    m3->lK = 4;
    m3->data[0] = 2.0; m3->data[1] = 3.0; m3->data[2] = 4.0; m3->data[3] = 5.0;
    printf("First vector:\n");
    for (int i = 0; i < m3->lW; i++) {
        for (int j = 0; j < m3->lK; j++) {
            printf("%lf ", m3->data[i * m3->lK + j]);
        }
        printf("\n");
    }


    // Example vector (fourth matrix)
    Matrix2D* m4 = malloc(sizeof(Matrix2D) + 1 * 4 * sizeof(double));
    if (m4 == NULL) {
        return NULL;
    }
    m4->lW = 1;
    m4->lK = 4;
    m4->data[0] = 1.0; m4->data[1] = 3.0; m4->data[2] = 9.0; m4->data[3] = 5.0;
    printf("Second vector:\n");
    for (int i = 0; i < m4->lW; i++) {
        for (int j = 0; j < m4->lK; j++) {
            printf("%lf ", m4->data[i * m4->lK + j]);
        }
        printf("\n");
    }


    // Example dot product
    double dot_result = dot_product(m3, m4);
    if (!isnan(dot_result)) {
        printf("Result of dot product:\n%lf\n", dot_result);
    }
    else {
        printf("Error (invalid matrix dimensions)\n");
    }

    printf("\n");




    // Example transposition
    transpose(m1);
    printf("First matrix after transposition:\n");
    for (int i = 0; i < m1->lW; i++) {
        for (int j = 0; j < m1->lK; j++) {
            printf("%lf ", m1->data[i * m1->lK + j]);
        }
        printf("\n");
    }

    printf("\n");



    // Example matrix copy
    Matrix2D* copy = copy_matrix(m2);
    if (copy) {
        printf("Copy of the second matrix:\n");
        for (int i = 0; i < copy->lW; i++) {
            for (int j = 0; j < copy->lK; j++) {
                printf("%lf ", copy->data[i * copy->lK + j]);
            }
            printf("\n");
        }
        free(copy);
    }
    else {
        printf("Error\n");
    }


    // Free memory
    free(m1);
    free(m2);
    free(m3);
    free(m4);
    return 0;
}