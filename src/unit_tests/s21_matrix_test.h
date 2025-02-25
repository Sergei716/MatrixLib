#ifndef S21_MATRIX_TEST
#define S21_MATRIX_TEST

#include <check.h>
#include <math.h>

#include "../s21_matrix.h"

#define s21_tol 0.1
#define ZERO_MTX \
  (matrix_t) { NULL, 0, 0 }
#define IDENTITY_MATRIX 2

Suite* suite_create_matrix_test();
Suite* suite_eq_matrix_test();
Suite* suite_sum_matrix_test();
Suite* suite_sub_matrix_test();
Suite* suite_remove_matrix_test();
Suite* suite_mult_matrix_test();
Suite* suite_mult_number_test();
Suite* suite_transpose_test();
Suite* suite_calc_complements_test();
Suite* suite_determinant_test();
Suite* suite_inverse_matrix_test();

void s21_fill(matrix_t*, double);
void s21_gen_matrix(matrix_t*);
void s21_anti_gen_matrix(matrix_t*);
void s21_init_matrix(double, matrix_t*);

#endif