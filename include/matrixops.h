#ifndef matrixops_h
#define matrixops_h

#include <stdlib.h>

void triplet_to_compcol (
    int nrow, int ncol, int nz,
    double *At, // in: Elements of A (triplet)
    int *Ati, // in: Row indexes of A
    int *Atj, // in: Column indexes of A
    double *A, // out: Elements of A (compcol)
    int *Ap, // out: Column pointer of A
    int *Ai // out: Row indexes of A
    );

void matrix_vector_mult (
    int m, int n, int nz,
    double *A, // in: Elements of A (compcol)
    int *Ap, // in: Column pointer of A
    int *Ai, // in: Row indexes of A
    double *x, // in: Vector
    double *y // out: Resulting vector y<-Ax
    );

#endif
