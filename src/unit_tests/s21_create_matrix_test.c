#include "s21_matrix_test.h"

START_TEST(S21_CREATE_MATRIX_TEST_1) {
  matrix_t A = {0};
  int ret_value = s21_create_matrix(5, 5, &A);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(A.rows, 5);
  ck_assert_int_eq(A.columns, 5);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(S21_CREATE_MATRIX_TEST_2) {
  matrix_t A = {0};
  int ret_value = s21_create_matrix(-1, 0, &A);
  ck_assert_int_eq(ret_value, ERROR_M);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.matrix == NULL, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(S21_CREATE_MATRIX_TEST_3) {
  matrix_t *A = (matrix_t *)malloc(sizeof(matrix_t));
  int ret_value = s21_create_matrix(5, 5, A);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(A->rows, 5);
  ck_assert_int_eq(A->columns, 5);
  s21_remove_matrix(A);
  free(A);
}
END_TEST

START_TEST(S21_CREATE_MATRIX_TEST_4) {
  matrix_t *A = NULL;
  int ret_value = s21_create_matrix(5, 5, A);
  ck_assert_int_eq(ret_value, ERROR_M);
  s21_remove_matrix(A);
}
END_TEST

START_TEST(S21_CREATE_MATRIX_TEST_5) {
  matrix_t A = {0};
  int ret_value = s21_create_matrix(1, 3, &A);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(A.rows, 1);
  ck_assert_int_eq(A.columns, 3);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(S21_CREATE_MATRIX_TEST_6) {
  matrix_t A = {0};
  int ret_value = s21_create_matrix(0, 1, &A);
  ck_assert_int_eq(ret_value, ERROR_M);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_01) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_02) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_03) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_04) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(2, 4, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_05) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(10, 15, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_06) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(res, ERROR_M);
}
END_TEST

START_TEST(s21_create_matrix_07) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(1, 0, &A);
  ck_assert_int_eq(res, ERROR_M);
}
END_TEST

START_TEST(s21_create_matrix_08) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(0, 1, &A);
  ck_assert_int_eq(res, ERROR_M);
}
END_TEST

START_TEST(s21_create_matrix_09) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(-1, 1, &A);
  ck_assert_int_eq(res, ERROR_M);
}
END_TEST

Suite *suite_create_matrix_test() {
  Suite *s = suite_create("\033[45m-=s21_create_matrix_test=-\033[0m");
  TCase *tc = tcase_create("s21_create_matrix_test");

  tcase_add_test(tc, S21_CREATE_MATRIX_TEST_1);
  tcase_add_test(tc, S21_CREATE_MATRIX_TEST_2);
  tcase_add_test(tc, S21_CREATE_MATRIX_TEST_3);
  tcase_add_test(tc, S21_CREATE_MATRIX_TEST_4);
  tcase_add_test(tc, S21_CREATE_MATRIX_TEST_5);
  tcase_add_test(tc, S21_CREATE_MATRIX_TEST_6);
  tcase_add_test(tc, s21_create_matrix_01);
  tcase_add_test(tc, s21_create_matrix_02);
  tcase_add_test(tc, s21_create_matrix_03);
  tcase_add_test(tc, s21_create_matrix_04);
  tcase_add_test(tc, s21_create_matrix_05);
  tcase_add_test(tc, s21_create_matrix_06);
  tcase_add_test(tc, s21_create_matrix_07);
  tcase_add_test(tc, s21_create_matrix_08);
  tcase_add_test(tc, s21_create_matrix_09);

  suite_add_tcase(s, tc);

  return s;
}
