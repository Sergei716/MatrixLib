#include "s21_matrix_test.h"

START_TEST(calc_determinant_core) {
  matrix_t A = ZERO_MTX;
  matrix_t B = ZERO_MTX;
  matrix_t C = ZERO_MTX;
  matrix_t D = ZERO_MTX;
  double A_result = 0.0;
  double B_result = 0.0;
  double C_result = 0.0;
  double D_result = 0.0;

  double test_1[3][3][3] = {{{1350.717, 250.7127, 340.77},
                             {450.707, 520.717, 660.77},
                             {770.707, 840.717, 9750.77}},

                            {{191.709, 2920.797, 3920.707},
                             {491.709, 590.7097, 690.797},
                             {791.71, 890.71, 990.71}},

                            {{1901.757, 291.705, 3901.71},
                             {491.75, 5901.705, 6901.75},
                             {7901.775, 8901.7050, 99001.75}}};

  double test_2[1][5][5] = {{{13, 25, 30, 25, 30},
                             {45, 52, 60, 50, 66},
                             {77, 84, 97, 84, 97},
                             {77, 84, 97, 84, 97},
                             {77, 84, 97, 84, 97}}};

  double answer_1 = 5125994629.3762889999;

  double answer_2 = 52361913.725383336231;

  double answer_3 = 831152331541.16470493;

  double answer_4 = 0;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &C);
  s21_create_matrix(5, 5, &D);
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      for (int z = 0; z < 3; z++) {
        if (x == 0) A.matrix[y][z] = test_1[x][y][z];
        if (x == 1) B.matrix[y][z] = test_1[x][y][z];
        if (x == 2) C.matrix[y][z] = test_1[x][y][z];
      }
    }
  }
  for (int x = 0; x < 1; x++) {
    for (int y = 0; y < 5; y++) {
      for (int z = 0; z < 5; z++) {
        if (x == 0) D.matrix[y][z] = test_2[x][y][z];
      }
    }
  }
  s21_determinant(&A, &A_result);
  s21_determinant(&B, &B_result);
  s21_determinant(&C, &C_result);
  s21_determinant(&D, &D_result);
  ck_assert_double_eq_tol(A_result, answer_1, 1e-6);
  ck_assert_double_eq_tol(B_result, answer_2, 1e-6);
  ck_assert_double_eq_tol(C_result, answer_3, 1e-6);
  ck_assert_double_eq_tol(D_result, answer_4, 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(determinant_hardcoded) {
  const int rows = 3;
  const int cols = 3;
  matrix_t m1 = {0};

  s21_create_matrix(rows, cols, &m1);
  int m = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m1.matrix[i][j] = m++;
    }
  }
  m1.matrix[2][2] = 0;
  double result;
  int got = s21_determinant(&m1, &result);
  ck_assert_double_eq_tol(result, 27, 1e-6);
  ck_assert_int_eq(got, 0);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(test_s21_determinant) {
  matrix_t temp;
  double result;
  int result_defolt;
  s21_create_matrix(3, 2, &temp);
  s21_gen_matrix(&temp);
  result_defolt = s21_determinant(&temp, &result);
  ck_assert_int_eq(result_defolt, 2);
  s21_remove_matrix(&temp);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  matrix_t temp = ZERO_MTX;
  double result = 0.0;
  int result_defolt = 0;
  s21_create_matrix(3, 3, &temp);
  s21_gen_matrix(&temp);
  result_defolt = s21_determinant(&temp, &result);
  ck_assert_int_eq(result_defolt, 0);
  ck_assert_uint_eq(result, 0);
  s21_remove_matrix(&temp);
}
END_TEST

START_TEST(test_s21_determinant_3) {
  matrix_t temp = ZERO_MTX;
  double result = 0.0;
  int result_defolt = 0;
  s21_create_matrix(3, 3, &temp);
  temp.matrix[0][0] = 0;
  temp.matrix[0][1] = 9;
  temp.matrix[0][2] = 5;

  temp.matrix[1][0] = 4;
  temp.matrix[1][1] = 3;
  temp.matrix[1][2] = -5;

  temp.matrix[2][0] = -1;
  temp.matrix[2][1] = 6;
  temp.matrix[2][2] = -4;
  result_defolt = s21_determinant(&temp, &result);
  ck_assert_int_eq(result_defolt, 0);
  ck_assert_uint_eq(result, 324);
  s21_remove_matrix(&temp);
}
END_TEST

START_TEST(test_s21_determinant_5) {
  matrix_t temp = ZERO_MTX;
  double result = 0.0;
  int result_defolt = 0;
  s21_create_matrix(3, 3, &temp);
  temp.matrix[0][0] = 1;
  temp.matrix[1][1] = 1;
  temp.matrix[2][2] = 1;

  result_defolt = s21_determinant(&temp, &result);
  ck_assert_int_eq(result_defolt, 0);
  ck_assert_uint_eq(result, 1);
  s21_remove_matrix(&temp);
}
END_TEST

START_TEST(s21_determinant_test_1) {
  matrix_t result1;
  double result2 = 0.0;
  s21_create_matrix(3, 3, &result1);
  result1.matrix[0][0] = 1;
  result1.matrix[0][1] = 2;
  result1.matrix[0][2] = 3;

  result1.matrix[1][0] = 4;
  result1.matrix[1][1] = 5;
  result1.matrix[1][2] = 6;

  result1.matrix[2][0] = 7;
  result1.matrix[2][1] = 8;
  result1.matrix[2][2] = 9;
  double expected_result = 0;
  s21_determinant(&result1, &result2);
  ck_assert_ldouble_eq(expected_result, result2);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t result1;
  double result3 = 0.0;
  s21_create_matrix(3, 4, &result1);
  int actual_result = IDENTITY_MATRIX;
  int expected_result = s21_determinant(&result1, &result3);
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(s21_determinant_01) {
  int res = 0;
  double determ = 0.0;
  matrix_t A = {NULL, 0, 0};

  res = s21_determinant(&A, &determ);
  ck_assert_int_eq(res, ERROR_M);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_02) {
  int res = 0;
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(1, 2, &A);

  res = s21_determinant(&A, &determ);
  ck_assert_int_eq(res, ERROR_C);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_03) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(1.0, &A);

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 1.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_04) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 4000.87;
  A.matrix[0][1] = 454.0;
  A.matrix[0][2] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 1.897;
  A.matrix[1][2] = 3.0;
  A.matrix[2][0] = 0.000087;
  A.matrix[2][1] = 2.5668;
  A.matrix[2][2] = 1.0;

  s21_determinant(&A, &determ);
  ck_assert_double_eq_tol(determ, -24105.996724156, 1e-7);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_05) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = -677700.0;
  A.matrix[0][1] = 654.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = -0.00001;

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, -1301.223);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_06) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(8, 8, &A);
  s21_init_matrix(1.0, &A);

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 0.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant1) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j;
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant2) {
  const int size = 4;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j + i;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant3) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][1] = 6;
  m.matrix[0][2] = -2;
  m.matrix[0][3] = -1;
  m.matrix[0][4] = 5;
  m.matrix[1][3] = -9;
  m.matrix[1][4] = -7;
  m.matrix[2][1] = 15;
  m.matrix[2][2] = 35;
  m.matrix[3][1] = -1;
  m.matrix[3][2] = -11;
  m.matrix[3][3] = -2;
  m.matrix[3][4] = 1;
  m.matrix[4][0] = -2;
  m.matrix[4][1] = -2;
  m.matrix[4][2] = 3;
  m.matrix[4][4] = -2;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 2480, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant4) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 3;
  m.matrix[0][2] = 1;
  m.matrix[1][0] = 7;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 1;
  m.matrix[2][0] = 9;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = 1;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -32, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant5) {
  const int size = 2;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = -5;
  m.matrix[0][1] = -4;
  m.matrix[1][0] = -2;
  m.matrix[1][1] = -3;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 7, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

Suite *suite_determinant_test(void) {
  Suite *s = suite_create("\033[45m-=s21_determinants_test=-\033[0m");
  TCase *tc = tcase_create("s21_determinants_test");

  tcase_add_test(tc, calc_determinant_core);

  tcase_add_test(tc, s21_determinant_01);
  tcase_add_test(tc, s21_determinant_02);
  tcase_add_test(tc, s21_determinant_03);
  tcase_add_test(tc, s21_determinant_04);
  tcase_add_test(tc, s21_determinant_05);
  tcase_add_test(tc, s21_determinant_06);

  tcase_add_test(tc, determinant1);
  tcase_add_test(tc, determinant2);
  tcase_add_test(tc, determinant3);
  tcase_add_test(tc, determinant4);
  tcase_add_test(tc, determinant5);

  tcase_add_test(tc, determinant_hardcoded);

  tcase_add_test(tc, test_s21_determinant);
  tcase_add_test(tc, test_s21_determinant_2);
  tcase_add_test(tc, test_s21_determinant_3);
  tcase_add_test(tc, test_s21_determinant_5);

  tcase_add_test(tc, s21_determinant_test_1);
  tcase_add_test(tc, s21_determinant_test_2);

  suite_add_tcase(s, tc);

  return s;
}