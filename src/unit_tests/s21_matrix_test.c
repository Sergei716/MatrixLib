#include "s21_matrix_test.h"

#include <check.h>

int main(void) {
  int failed = 0;
  Suite *suite[] = {suite_create_matrix_test(),    suite_eq_matrix_test(),
                    suite_remove_matrix_test(),    suite_sum_matrix_test(),
                    suite_sub_matrix_test(),       suite_mult_matrix_test(),
                    suite_mult_number_test(),      suite_transpose_test(),
                    suite_calc_complements_test(), suite_determinant_test(),
                    suite_inverse_matrix_test(),   NULL};

  for (int i = 0; suite[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(suite[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}

void s21_init_matrix(double value, matrix_t *A) {
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) return;
  for (int x = 0; x < A->rows; x += 1) {
    for (int y = 0; y < A->columns; value += 1.0, y += 1)
      A->matrix[x][y] = value;
  }
}

void s21_fill(matrix_t *matrixStruct, double value) {
  for (int i = 0; i < matrixStruct->rows; i++) {
    for (int j = 0; j < matrixStruct->columns; j++) {
      matrixStruct->matrix[i][j] = value;
    }
  }
}

void s21_gen_matrix(matrix_t *A) {
  double num = 1;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++, num++) {
      A->matrix[i][j] = num;
    }
  }
}

void s21_anti_gen_matrix(matrix_t *A) {
  double num = 32;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++, num--) {
      A->matrix[i][j] = num;
    }
  }
}