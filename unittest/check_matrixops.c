#include <check.h>
#include "matrixops.h"

START_TEST(test_matrix_ops) {
  int nrow = 3, ncol = 3, nz = 5;
  double At[5] = {1.2, -2, 3.1, 4.9, 99};
  int Ati[5] = {1, 1, 2, 3, 3};
  int Atj[5] = {1, 2, 2, 2, 3};
  double A[5];
  int Ap[ncol+1], Ai[nz];
  triplet_to_compcol(nrow, ncol, nz, At, Ati, Atj, A, Ap, Ai);
} END_TEST

Suite * matrix_ops_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Matrix Ops");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_matrix_ops);
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
