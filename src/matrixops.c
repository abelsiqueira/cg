#include "matrixops.h"
#include <stdio.h>

#define UNUSED(x) (void)(x);
#define PRINT_ARRAY(V, size, type) \
    for (k = 0; k < size; k++) \
      printf(#type" ", V[k]); \
    printf("\n");

void triplet_to_compcol (int ncol, int nz, double *At, int *Ati, int
    *Atj, double *A, int *Ap, int *Ai) {
  int *order_ind, k, p, best_k;

  order_ind = (int *) malloc(sizeof(int)*nz);
  for (k = 0; k < nz; k++)
    order_ind[k] = k;

  for (k = 0; k < nz; k++) {
    best_k = k;
    for (p = k+1; p < nz; p++) {
      if ( (Atj[order_ind[p]] < Atj[order_ind[best_k]]) ||
           ( (Atj[order_ind[p]] == Atj[order_ind[best_k]]) &&
             (Ati[order_ind[p]] < Ati[order_ind[best_k]]) ) ) {
        best_k = p;
      }
    }
    if (best_k != k) {
      p = order_ind[k];
      order_ind[k] = order_ind[best_k];
      order_ind[best_k] = p;
    }
  }

  p = 0;
  Ap[0] = 0;
  for (k = 0; k < ncol; k++) {
    Ap[k+1] = Ap[k];
    if (p == nz)
      continue;
    while (Atj[order_ind[p]] == k) {
      A[p] = At[order_ind[p]];
      Ai[p] = Ati[order_ind[p]];
      Ap[k+1]++;
      p++;
      if (p == nz)
        break;
    }
  }
}

void matrix_vector_mult (int nrow, int ncol, bool trans, double *A, int
    *Ap, int *Ai, double *x, double *y) {
  int j, k;
  if (trans) {
    k = 0;
    for (j = 0; j < ncol; j++) {
      y[j] = 0.0;
      while (k < Ap[j+1]) {
        y[j] += A[k]*x[Ai[k]];
        k++;
      }
    }
    PRINT_ARRAY(y, ncol, %lf);
  } else {
    for (k = 0; k < nrow; k++)
      y[k] = 0.0;
    k = 0;
    for (j = 0; j < ncol; j++) {
      while (k < Ap[j+1]) {
        y[Ai[k]] += A[k]*x[j];
        k++;
      }
    }
  }
}
