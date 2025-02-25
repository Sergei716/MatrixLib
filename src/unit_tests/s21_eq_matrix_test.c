#include "s21_matrix_test.h"

START_TEST(S21_EQ_MATRIX_TEST_1) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 4, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = (&B)->matrix[i][j] = (i + 1) * j;
    }
  }

  int ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(S21_EQ_MATRIX_TEST_2) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(4, 3, &A);
  s21_create_matrix(3, 4, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = (i + 1) * j;
    }
  }

  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      (&B)->matrix[i][j] = (i + 1) * j;
    }
  }

  int ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(S21_EQ_MATRIX_TEST_3) {
  matrix_t A = {0};
  matrix_t *B = NULL;

  s21_create_matrix(4, 3, &A);
  s21_create_matrix(3, 4, B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = (i + 1) * j;
    }
  }

  int ret = s21_eq_matrix(&A, B);
  ck_assert_int_eq(ret, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(B);
}
END_TEST

START_TEST(S21_EQ_MATRIX_TEST_4) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 4, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = (&B)->matrix[i][j] = (i + 1) * j;
    }
  }

  (&A)->matrix[0][0] += 0.000000001;

  int ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t temp3;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_create_matrix(3, 3, &temp3);
  s21_gen_matrix(&temp);
  s21_gen_matrix(&temp2);
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp2), 1);
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp3), 0);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&temp3);
}
END_TEST

START_TEST(test_s21_eq_matrix_2) {
  matrix_t temp;
  matrix_t temp2;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_gen_matrix(&temp);
  s21_gen_matrix(&temp2);
  temp2.matrix[1][1] = 0;
  temp2.matrix[1][2] = 77;
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp2), 0);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
}
END_TEST

START_TEST(test_s21_eq_matrix_3) {
  matrix_t temp;
  matrix_t temp2;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(2, 3, &temp2);
  s21_gen_matrix(&temp);
  s21_gen_matrix(&temp2);
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp2), 0);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
}
END_TEST

START_TEST(test_s21_eq_matrix_4) {
  matrix_t temp;
  matrix_t temp2;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 21, &temp2);
  s21_gen_matrix(&temp);
  s21_gen_matrix(&temp2);
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp2), 0);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
}
END_TEST

START_TEST(test_s21_eq_matrix_5) {
  matrix_t temp;
  matrix_t temp2;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_gen_matrix(&temp);
  s21_gen_matrix(&temp2);
  temp.matrix[0][1] = 4.67773;
  temp2.matrix[0][1] = 4.67774;
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp2), 0);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
}
END_TEST

START_TEST(s21_eq_matrix_01) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(3, 2, &B);
  s21_init_matrix(1.0, &B);

  res = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_eq_matrix_02) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(3, 2, &B);
  s21_init_matrix(2.0, &B);

  res = s21_eq_matrix(&B, &A);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_03) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 4, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(3, 4, &B);
  s21_init_matrix(1.0, &B);

  res = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_04) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_init_matrix(10.0, &A);

  s21_create_matrix(3, 2, &B);
  s21_init_matrix(-10.0, &B);

  res = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_05) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(3, 3, &B);
  s21_init_matrix(1.0, &B);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_06) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(10, 10, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(10, 10, &B);
  s21_init_matrix(1.0, &B);

  res = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

Suite *suite_eq_matrix_test() {
  Suite *s = suite_create("\033[45m-=s21_eq_matrix_test=-\033[0m");
  TCase *tc = tcase_create("s21_eq_matrix_test");

  tcase_add_test(tc, S21_EQ_MATRIX_TEST_1);
  tcase_add_test(tc, S21_EQ_MATRIX_TEST_2);
  tcase_add_test(tc, S21_EQ_MATRIX_TEST_3);
  tcase_add_test(tc, S21_EQ_MATRIX_TEST_4);
  tcase_add_test(tc, test_s21_eq_matrix);
  tcase_add_test(tc, test_s21_eq_matrix_2);
  tcase_add_test(tc, test_s21_eq_matrix_3);
  tcase_add_test(tc, test_s21_eq_matrix_4);
  tcase_add_test(tc, test_s21_eq_matrix_5);
  tcase_add_test(tc, s21_eq_matrix_01);
  tcase_add_test(tc, s21_eq_matrix_02);
  tcase_add_test(tc, s21_eq_matrix_03);
  tcase_add_test(tc, s21_eq_matrix_04);
  tcase_add_test(tc, s21_eq_matrix_05);
  tcase_add_test(tc, s21_eq_matrix_06);
  suite_add_tcase(s, tc);
  return s;
}
