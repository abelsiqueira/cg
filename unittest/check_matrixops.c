#include <check.h>
#include "matrixops.h"
#include <stdio.h>

START_TEST(test_triplet_to_compcol) {
  int i;
  int ncol = 3, nz = 5;
  double At[5] = {1.2, -2, 3.1, 4.9, 99};
  int Ati[5] = {0, 2, 1, 0, 2};
  int Atj[5] = {0, 1, 2, 1, 2};
  double A[5];
  int Ap[ncol+1], Ai[nz];
  triplet_to_compcol(ncol, nz, At, Ati, Atj, A, Ap, Ai);
  int expected_Ai[5] = {0, 0, 2, 1, 2};
  int expected_Ap[4] = {0, 1, 3, 5};
  for (i = 0; i < nz; i++)
    ck_assert_int_eq(Ai[i], expected_Ai[i]);
  for (i = 0; i <= ncol; i++)
    ck_assert_int_eq(Ap[i], expected_Ap[i]);
} END_TEST

START_TEST(test_matrix_vector_mult) {
  int i;
  double A[12] = {2, 6, 4, 1, 1, 2, 10, 7, 9, 2, 4, 5};
  int   Ai[12] = {3, 2, 0, 1, 0, 2,  3, 0, 1, 0, 1, 3};
  int    Ap[7] = {0, 1, 2, 4, 7, 9, 12};
  double x[6] = {1.0, 1.5, -0.2, 1.4, 0.8, 1.3};
  double Ax[4] = {8.8, 12.2, 11.8, 22.5};
  double AtAx[6] = {45.0, 70.8, 47.4, 257.4, 171.4, 178.9};
  double y[4], z[6];

  int nrow = 4, ncol = 6;
  matrix_vector_mult(nrow, ncol, false, A, Ap, Ai, x, y);
  matrix_vector_mult(nrow, ncol, true, A, Ap, Ai, y, z);
  for (i = 0; i < nrow; i++)
    ck_assert_int_eq(y[i], Ax[i]);
  for (i = 0; i < ncol; i++)
    ck_assert_int_eq(z[i], AtAx[i]);
} END_TEST

Suite * matrix_ops_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Matrix Ops");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_triplet_to_compcol);
  tcase_add_test(tc_core, test_matrix_vector_mult);
  suite_add_tcase(s, tc_core);

  return s;
}

int main (void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = matrix_ops_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
