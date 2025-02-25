#include "s21_matrix_test.h"

START_TEST(s21_mult_number_01) {
  int res = 0;
  double number = 3.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);

  s21_init_matrix(1.0, &A);

  s21_mult_number(&A, number, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 3.0;
  X.matrix[0][1] = 6.0;
  X.matrix[0][2] = 9.0;
  X.matrix[0][3] = 12.0;
  X.matrix[1][0] = 15.0;
  X.matrix[1][1] = 18.0;
  X.matrix[1][2] = 21.0;
  X.matrix[1][3] = 24.0;
  X.matrix[2][0] = 27.0;
  X.matrix[2][1] = 30.0;
  X.matrix[2][2] = 33.0;
  X.matrix[2][3] = 36.0;
  X.matrix[3][0] = 39.0;
  X.matrix[3][1] = 42.0;
  X.matrix[3][2] = 45.0;
  X.matrix[3][3] = 48.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_mult_number_02) {
  int res = 0;
  double number = 5.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_mult_number(&A, number, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 5.0;
  X.matrix[0][1] = 10.0;
  X.matrix[0][2] = 15.0;
  X.matrix[0][3] = 20.0;
  X.matrix[1][0] = 25.0;
  X.matrix[1][1] = 30.0;
  X.matrix[1][2] = 35.0;
  X.matrix[1][3] = 40.0;
  X.matrix[2][0] = 45.0;
  X.matrix[2][1] = 50.0;
  X.matrix[2][2] = 55.0;
  X.matrix[2][3] = 60.0;
  X.matrix[3][0] = 65.0;
  X.matrix[3][1] = 70.0;
  X.matrix[3][2] = 75.0;
  X.matrix[3][3] = 80.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_mult_number_03) {
  int res = 0;
  double number = 2.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(2.0, &A);

  s21_mult_number(&A, number, &Z);

  s21_create_matrix(4, 2, &X);

  X.matrix[0][0] = 4.0;
  X.matrix[0][1] = 6.0;
  X.matrix[1][0] = 8.0;
  X.matrix[1][1] = 10.0;
  X.matrix[2][0] = 12.0;
  X.matrix[2][1] = 14.0;
  X.matrix[3][0] = 16.0;
  X.matrix[3][1] = 18.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_mult_number_04) {
  int res = 0;
  double number = -2.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(2.0, &A);

  s21_mult_number(&A, number, &Z);

  s21_create_matrix(4, 2, &X);

  X.matrix[0][0] = -4.0;
  X.matrix[0][1] = -6.0;
  X.matrix[1][0] = -8.0;
  X.matrix[1][1] = -10.0;
  X.matrix[2][0] = -12.0;
  X.matrix[2][1] = -14.0;
  X.matrix[3][0] = -16.0;
  X.matrix[3][1] = -18.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_mult_number_05) {
  int res = 0;
  double number = 2.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(2.0, &A);

  s21_mult_number(&A, number, &Z);

  s21_create_matrix(1, 1, &X);

  X.matrix[0][0] = 4.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_mult_number_06) {
  int res = 0;
  double number = 2.0;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(0, 0, &A);

  res = s21_mult_number(&A, number, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, ERROR_M);
}
END_TEST

START_TEST(test_s21_mult_number) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  matrix_t result_defolt;
  double num = 777.777;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_create_matrix(3, 3, &result_defolt);
  s21_gen_matrix(&temp);
  s21_gen_matrix(&temp2);
  for (int i = 0; (i < temp.rows); i++) {
    for (int j = 0; j < temp.columns; j++) {
      result_defolt.matrix[i][j] = temp.matrix[i][j] * 777.777;
    }
  }
  ck_assert_int_eq(s21_mult_number(&temp, num, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(test_s21_mult_number_2) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  matrix_t result_defolt;
  double num = 777.777;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_create_matrix(3, 3, &result_defolt);
  s21_gen_matrix(&temp);
  s21_gen_matrix(&temp2);
  for (int i = 0; i < temp.rows; i++) {
    for (int j = 0; j < temp.columns; j++) {
      result_defolt.matrix[i][j] = temp.matrix[i][j] * 777.777;
    }
  }
  ck_assert_int_eq(s21_mult_number(&temp, num, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(mult_num) {
  const int rows = 2;
  const int cols = 2;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 1;
  m.matrix[1][0] = 1;
  m.matrix[1][1] = 1;
  check.matrix[0][0] = 2;
  check.matrix[0][1] = 2;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = 2;
  int num = 2;
  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_number(&m, num, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_number_test_1) {
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;
  s21_create_matrix(4, 4, &result1);
  s21_fill(&result1, 3);
  int expected_result = s21_create_matrix(4, 4, &result2);
  s21_fill(&result2, 30);
  int actual_result = s21_mult_number(&result1, 10, &result3);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_double_eq(result3.matrix[i][j], result2.matrix[i][j]);
    }
  }
  ck_assert_int_eq(expected_result, actual_result);
  s21_remove_matrix(&result1);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result3);
}
END_TEST

START_TEST(s21_mult_number_test_2) {
  matrix_t result1;
  matrix_t result3;
  s21_create_matrix(2, 2, &result1);
  int expected_result = 0;
  int actual_result = s21_mult_number(&result1, 3, &result3);
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result3);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(mult_number_core) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t A_result;
  matrix_t B_result;
  matrix_t C_result;

  double main_number = 21.042;

  double test[3][3][3] = {{{1350.717, 250.7127, 340.77},
                           {450.707, 520.717, 660.77},
                           {770.707, 840.717, 9750.77}},
                          {{191.709, 2920.797, 3920.707},
                           {491.709, 590.7097, 690.797},
                           {791.71, 890.71, 990.71}},
                          {{1901.757, 291.705, 3901.71},
                           {491.75, 5901.705, 6901.75},
                           {7901.775, 8901.7050, 99001.75}}};
  double answer_1[3][3] = {{28421.787114, 5275.4966334, 7170.48234},
                           {9483.776694, 10956.927114, 13903.92234},
                           {16217.216694, 17690.367114, 205175.70234}};
  double answer_2[3][3] = {{4033.940778, 61459.410474, 82499.516694},
                           {10346.540778, 12429.7135074, 14535.750474},
                           {16659.16182, 18742.31982, 20846.51982}};
  double answer_3[3][3] = {{40016.770794, 6138.05661, 82099.78182},
                           {10347.4035, 124183.67661, 145226.6235},
                           {166269.14955, 187309.67661, 2083194.8235}};

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
  s21_mult_number(&A, main_number, &A_result);
  s21_mult_number(&B, main_number, &B_result);
  s21_mult_number(&C, main_number, &C_result);
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

Suite *suite_mult_number_test(void) {
  Suite *s = suite_create("\033[45m-=s21_mult_number_test=-\033[0m");
  TCase *tc = tcase_create("s21_mult_number_test");

  tcase_add_test(tc, s21_mult_number_01);
  tcase_add_test(tc, s21_mult_number_02);
  tcase_add_test(tc, s21_mult_number_03);
  tcase_add_test(tc, s21_mult_number_04);
  tcase_add_test(tc, s21_mult_number_05);
  tcase_add_test(tc, s21_mult_number_06);
  tcase_add_test(tc, test_s21_mult_number);
  tcase_add_test(tc, test_s21_mult_number_2);
  tcase_add_test(tc, mult_num);
  tcase_add_test(tc, s21_mult_number_test_1);
  tcase_add_test(tc, s21_mult_number_test_2);
  tcase_add_test(tc, mult_number_core);

  suite_add_tcase(s, tc);

  return s;
}
