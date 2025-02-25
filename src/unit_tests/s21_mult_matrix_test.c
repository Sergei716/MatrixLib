#include "s21_matrix_test.h"

START_TEST(s21_mult_matrix_test_1) {
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;
  matrix_t result4;
  s21_create_matrix(4, 4, &result1);
  s21_create_matrix(4, 4, &result2);
  s21_fill(&result1, 3);
  s21_fill(&result2, 3);
  int expected_result = s21_create_matrix(4, 4, &result3);
  s21_fill(&result3, 36);
  int actual_result = s21_mult_matrix(&result1, &result2, &result4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_double_eq(result3.matrix[i][j], result4.matrix[i][j]);
    }
  }
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result4);
  s21_remove_matrix(&result3);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;
  matrix_t result4;
  s21_create_matrix(4, 4, &result1);
  s21_create_matrix(3, 3, &result2);
  s21_fill(&result1, 3);
  s21_fill(&result2, 3);
  int expected_result = s21_create_matrix(4, 4, &result3);
  expected_result = 1;
  int actual_result = s21_mult_matrix(&result1, &result2, &result4);
  ck_assert_uint_ne(expected_result, actual_result);
  s21_remove_matrix(&result3);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(test_s21_mult_matrix_2) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  matrix_t result_defolt;
  s21_create_matrix(3, 2, &temp);
  s21_create_matrix(2, 3, &temp2);
  s21_create_matrix(3, 3, &result_defolt);
  s21_gen_matrix(&temp);
  s21_gen_matrix(&temp2);
  result_defolt.matrix[0][0] = 9;
  result_defolt.matrix[0][1] = 12;
  result_defolt.matrix[0][2] = 15;
  result_defolt.matrix[1][0] = 19;
  result_defolt.matrix[1][1] = 26;
  result_defolt.matrix[1][2] = 33;
  result_defolt.matrix[2][0] = 29;
  result_defolt.matrix[2][1] = 40;
  result_defolt.matrix[2][2] = 51;
  ck_assert_int_eq(s21_mult_matrix(&temp, &temp2, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(test_s21_mult_matrix_3) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_gen_matrix(&temp);
  s21_gen_matrix(&temp2);
  ck_assert_int_eq(s21_mult_matrix(&temp, &temp2, &result), 0);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_4) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  matrix_t result_defolt;
  s21_create_matrix(2, 3, &temp);
  s21_create_matrix(3, 2, &temp2);
  s21_create_matrix(2, 2, &result_defolt);
  s21_gen_matrix(&temp);
  s21_gen_matrix(&temp2);
  result_defolt.matrix[0][0] = 22;
  result_defolt.matrix[0][1] = 28;
  result_defolt.matrix[1][0] = 49;
  result_defolt.matrix[1][1] = 64;
  ck_assert_int_eq(s21_mult_matrix(&temp, &temp2, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(s21_mult_matrix_01) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 90.0;
  X.matrix[0][1] = 100.0;
  X.matrix[0][2] = 110.0;
  X.matrix[0][3] = 120.0;
  X.matrix[1][0] = 202.0;
  X.matrix[1][1] = 228.0;
  X.matrix[1][2] = 254.0;
  X.matrix[1][3] = 280.0;
  X.matrix[2][0] = 314.0;
  X.matrix[2][1] = 356.0;
  X.matrix[2][2] = 398.0;
  X.matrix[2][3] = 440.0;
  X.matrix[3][0] = 426.0;
  X.matrix[3][1] = 484.0;
  X.matrix[3][2] = 542.0;
  X.matrix[3][3] = 600.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_02) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(-5.0, &B);

  s21_mult_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 30.0;
  X.matrix[0][1] = 40.0;
  X.matrix[0][2] = 50.0;
  X.matrix[0][3] = 60.0;
  X.matrix[1][0] = 46.0;
  X.matrix[1][1] = 72.0;
  X.matrix[1][2] = 98.0;
  X.matrix[1][3] = 124.0;
  X.matrix[2][0] = 62.0;
  X.matrix[2][1] = 104.0;
  X.matrix[2][2] = 146.0;
  X.matrix[2][3] = 188.0;
  X.matrix[3][0] = 78.0;
  X.matrix[3][1] = 136.0;
  X.matrix[3][2] = 194.0;
  X.matrix[3][3] = 252.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_03) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = -78.0;
  X.matrix[0][1] = -92.0;
  X.matrix[0][2] = -106.0;
  X.matrix[0][3] = -120.0;
  X.matrix[1][0] = 34.0;
  X.matrix[1][1] = 36.0;
  X.matrix[1][2] = 38.0;
  X.matrix[1][3] = 40.0;
  X.matrix[2][0] = 146.0;
  X.matrix[2][1] = 164.0;
  X.matrix[2][2] = 182.0;
  X.matrix[2][3] = 200.0;
  X.matrix[3][0] = 258.0;
  X.matrix[3][1] = 292.0;
  X.matrix[3][2] = 326.0;
  X.matrix[3][3] = 360.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_04) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(2, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = -25.0;
  X.matrix[0][1] = -34.0;
  X.matrix[0][2] = -43.0;
  X.matrix[0][3] = -52.0;
  X.matrix[1][0] = -13.0;
  X.matrix[1][1] = -18.0;
  X.matrix[1][2] = -23.0;
  X.matrix[1][3] = -28.0;
  X.matrix[2][0] = -1.0;
  X.matrix[2][1] = -2.0;
  X.matrix[2][2] = -3.0;
  X.matrix[2][3] = -4.0;
  X.matrix[3][0] = 11.0;
  X.matrix[3][1] = 14.0;
  X.matrix[3][2] = 17.0;
  X.matrix[3][3] = 20.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_05) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(1, 1, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &Z);

  s21_create_matrix(1, 1, &X);

  X.matrix[0][0] = -5.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_06) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  res = s21_mult_matrix(&A, &B, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, ERROR_M);
}
END_TEST

START_TEST(s21_mult_matrix_07) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  s21_create_matrix(2, 3, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(2, 2, &B);
  s21_init_matrix(1.0, &B);

  res = s21_mult_matrix(&A, &B, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, ERROR_C);
}
END_TEST

START_TEST(mult_matrix_core) {
  matrix_t A = {0};
  matrix_t B;
  matrix_t result;

  double test[3][3][3] = {{{1350.7017, 250.7127, 340.777},
                           {450.7017, 520.717, 660.777},
                           {7750.7017, 8640.717, 9750.777}},
                          {{191.709, 2920.797, 3920.7097},
                           {491.709, 590.7097, 690.7097},
                           {791.71, 890.71, 990.71}},
                          {{1901.757, 2901.705, 39001.751},
                           {4901.75, 5901.705, 69001.715},
                           {7901.7755, 8901.7050, 99001.75}}};
  double answer_1[3][3] = {
      {652015.9218796, 4396757.37872809, 5806490.13246968},
      {865588.5662283, 2212561.4377798, 2781373.19152139},
      {13454385.2462283, 36427496.2017798, 46016670.66552139}};
  double answer_2[3][3] = {
      {45662168.47753535, 52694966.3627685, 597174110.391289},
      {9288455.28976035, 11061482.843922, 128318963.3915695},
      {13700045.782575, 16373024.68665, 190420617.59436}};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int x = 0; x < 2; x++) {
    for (int y = 0; y < 3; y++) {
      for (int z = 0; z < 3; z++) {
        if (x == 0) A.matrix[y][z] = test[x][y][z];
        if (x == 1) B.matrix[y][z] = test[x][y][z];
      }
    }
  }
  s21_mult_matrix(&A, &B, &result);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], answer_1[i][j], s21_tol);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int x = 1; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      for (int z = 0; z < 3; z++) {
        if (x == 1) A.matrix[y][z] = test[x][y][z];
        if (x == 2) B.matrix[y][z] = test[x][y][z];
      }
    }
  }
  s21_mult_matrix(&A, &B, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], answer_2[i][j], s21_tol);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *suite_mult_matrix_test(void) {
  Suite *s = suite_create("\033[45m-=s21_mult_matrix_test=-\033[0m");
  TCase *tc = tcase_create("s21_mult_matrix_test");

  tcase_add_test(tc, s21_mult_matrix_test_1);
  tcase_add_test(tc, s21_mult_matrix_test_2);

  tcase_add_test(tc, test_s21_mult_matrix_2);
  tcase_add_test(tc, test_s21_mult_matrix_3);
  tcase_add_test(tc, test_s21_mult_matrix_4);

  tcase_add_test(tc, s21_mult_matrix_01);
  tcase_add_test(tc, s21_mult_matrix_02);
  tcase_add_test(tc, s21_mult_matrix_03);
  tcase_add_test(tc, s21_mult_matrix_04);
  tcase_add_test(tc, s21_mult_matrix_05);
  tcase_add_test(tc, s21_mult_matrix_06);
  tcase_add_test(tc, s21_mult_matrix_07);

  tcase_add_test(tc, mult_matrix_core);

  suite_add_tcase(s, tc);

  return s;
}