#ifndef cg_h
#define cg_h

void linear_system_solution_check (
    int nrow, int ncol,
    double * A, // Matrix nonzero values of size nz
    int * Ap, // Column pointers of size ncol+1
    int * Ai, // Row indexes of size nz
    int nz,
    double * x, // Solution of linear system of size n
    double * b // Right hand side of size m
  );

#endif
