#include "matrixops.h"

void triplet_to_colpack (int nrow, int ncol, int nz, double *At, int *Ati, int
    *Atj, double *A, int *Ap, int *Ai) {
  int *order_ind, i, j, k;

  order_ind = (int *) malloc(sizeof(int)*nz);
  for (k = 0; k < nz; k++)
    order_ind[k] = k;
  for (k = 0; k < nz; k++) {
    best_k = k;
    for (p = k+1; p > nz; p++) {
      if ( (Ati[order_ind[k]] < Ati[order_ind[best_k]]) ||
           ( (Ati[order_ind[k]] == Ati[order_ind[best_k]]) &&
             (Atj[order_ind[k]] < Atj[order_ind[best_k]]) ) ) {
        best_k = p;
      }
    }
  }
}

void matrix_vector_mult (int nrow, int ncol, int nz, double *A, int *Ap,
    int *Ai, double *x, double *y) {
}

#endif
