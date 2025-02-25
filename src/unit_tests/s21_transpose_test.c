#include "s21_matrix_test.h"

START_TEST(test_s21_transpose) {
  matrix_t temp;
  matrix_t result;
  matrix_t result_defolt;
  s21_create_matrix(3, 2, &temp);
  s21_create_matrix(2, 3, &result_defolt);
  s21_gen_matrix(&temp);
  result_defolt.matrix[0][0] = 1;
  result_defolt.matrix[0][1] = 3;
  result_defolt.matrix[0][2] = 5;
  result_defolt.matrix[1][0] = 2;
  result_defolt.matrix[1][1] = 4;
  result_defolt.matrix[1][2] = 6;
  ck_assert_int_eq(s21_transpose(&temp, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(s21_transpose_01) {
  int res = 0;
  matrix_t A = {0};

  res = s21_transpose(&A, &A);
  ck_assert_int_eq(res, ERROR_M);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_02) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t D = {0};

  s21_create_matrix(3, 4, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(3, 4, &D);
  s21_init_matrix(1.0, &D);
  res = s21_transpose(&A, &B);
  s21_init_matrix(1.0, &B);
  res = s21_eq_matrix(&B, &D);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(s21_transpose_03) {
  int res = 0;
  matrix_t A = {0};
  matrix_t T = {0};
  matrix_t B = {0};

  s21_create_matrix(2, 3, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 4.0;
  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 5.0;
  B.matrix[2][0] = 3.0;
  B.matrix[2][1] = 6.0;

  res = s21_transpose(&A, &T);
  res = s21_eq_matrix(&T, &B);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&T);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(transpose_matrix) {
  const int rows = 2;
  const int cols = 2;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t check = {0};
  s21_create_matrix(cols, rows, &check);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[1][0] = 3;
  m.matrix[1][1] = 4;
  check.matrix[0][0] = 1;
  check.matrix[0][1] = 3;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = 4;
  matrix_t res = {0};
  ck_assert_int_eq(s21_transpose(&m, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_core) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t A_result;
  matrix_t B_result;
  matrix_t C_result;

  double test[3][3][3] = {{{1350.717, 250.7127, 340.77},
                           {450.707, 520.717, 660.77},
                           {770.707, 840.717, 9750.77}},

                          {{191.709, 2920.797, 3920.707},
                           {491.709, 590.7097, 690.797},
                           {791.71, 890.71, 990.71}},

                          {{1901.757, 291.705, 3901.71},
                           {491.75, 5901.705, 6901.75},
                           {7901.775, 8901.7050, 99001.75}}};

  double answer_1[3][3] = {{1350.717, 450.707, 770.707},
                           {250.7127, 520.717, 840.717},
                           {340.77, 660.77, 9750.77}};

  double answer_2[3][3] = {{191.709, 491.709, 791.71},
                           {2920.797, 590.7097, 890.71},
                           {3920.707, 690.797, 990.71}};

  double answer_3[3][3] = {{1901.757, 491.75, 7901.775},
                           {291.705, 5901.705, 8901.7050},
                           {3901.71, 6901.75, 99001.75}};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &C);
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      for (int z = 0; z < 3; z++) {
        if (x == 0) A.matrix[y][z] = test[x][y][z];
        if (x == 1) B.matrix[y][z] = test[x][y][z];
        if (x == 2) C.matrix[y][z] = test[x][y][z];
      }
    }
  }

  s21_transpose(&A, &A_result);
  s21_transpose(&B, &B_result);
  s21_transpose(&C, &C_result);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(A_result.matrix[i][j], answer_1[i][j], s21_tol);
      ck_assert_double_eq_tol(B_result.matrix[i][j], answer_2[i][j], s21_tol);
      ck_assert_double_eq_tol(C_result.matrix[i][j], answer_3[i][j], s21_tol);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&A_result);
  s21_remove_matrix(&B_result);
  s21_remove_matrix(&C_result);
}
END_TEST

Suite *suite_transpose_test(void) {
  Suite *s = suite_create("\033[45m-=s21_transpose_test=-\033[0m");
  TCase *tc = tcase_create("s21_transpose_test");

  tcase_add_test(tc, test_s21_transpose);

  tcase_add_test(tc, s21_transpose_01);
  tcase_add_test(tc, s21_transpose_02);
  tcase_add_test(tc, s21_transpose_03);

  tcase_add_test(tc, transpose_matrix);
  tcase_add_test(tc, transpose_core);

  suite_add_tcase(s, tc);

  return s;
}