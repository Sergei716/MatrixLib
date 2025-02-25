#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flags = OK;
  if (result == NULL || rows <= 0 || columns <= 0) {
    if (result != NULL) {
      result->rows = result->columns = 0;
      result->matrix = NULL;
    }
    return ERROR_M;
  }

  result->rows = rows;
  result->columns = columns;
  result->matrix = malloc(rows * sizeof(double *));
  if (result->matrix == NULL) {
    flags = ERROR_M;
  }
  int i = 0;
  for (; i < rows && !flags; ++i) {
    result->matrix[i] = calloc(columns, sizeof(double));
    if (result->matrix[i] == NULL) flags = ERROR_M;
    if (flags) {
      for (int j = 0; j < i; ++j) free(result->matrix[j]);
      free(result->matrix);
      result->matrix = NULL;
    }
  }
  return flags;
}

void s21_remove_matrix(matrix_t *A) {
  if (A == NULL || A->matrix == NULL) return;
  for (int i = 0; i < A->rows; ++i) {
    if (A->matrix[i] != NULL) free(A->matrix[i]);
  }
  free(A->matrix);
  A->matrix = NULL;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flags = SUCCESS;
  if (is_checking_matrices(A, B)) flags = FAILURE;
  for (int i = 0; i < A->rows && flags != FAILURE; ++i)
    for (int j = 0; j < A->columns && flags; ++j)
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) flags = FAILURE;
  return flags;
}

int is_checking_matrices(matrix_t *A, matrix_t *B) {
  if (A == NULL || A->matrix == NULL || B == NULL || B->matrix == NULL ||
      A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0)
    return ERROR_M;
  return (A->columns == B->columns && A->rows == B->rows) ? OK : ERROR_C;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flags = is_checking_matrices(A, B);
  if (!flags) {
    flags = s21_create_matrix(A->rows, A->columns, result);
    if (!flags)
      for (int i = 0; i < A->rows; ++i)
        for (int j = 0; j < A->columns; ++j)
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
  }
  return flags;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flags = is_checking_matrices(A, B);
  if (!flags) {
    flags = s21_create_matrix(A->rows, B->columns, result);
    if (!flags)
      for (int i = 0; i < A->rows; ++i)
        for (int j = 0; j < A->columns; ++j)
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
  }
  return flags;
}

int s21_mult_number(matrix_t *A, double value, matrix_t *result) {
  if (A == NULL || A->matrix == NULL) return ERROR_M;
  int flags = s21_create_matrix(A->rows, A->columns, result);
  if (!flags)
    for (int i = 0; i < A->rows; ++i)
      for (int j = 0; j < A->columns; ++j)
        result->matrix[i][j] = value * A->matrix[i][j];
  return flags;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A->columns != B->rows) return ERROR_C;
  int flags = s21_create_matrix(A->rows, B->columns, result);
  if (!flags) {
    for (int i = 0; i < A->rows; ++i)
      for (int j = 0; j < B->columns; ++j)
        for (int k = 0; k < B->rows; ++k)
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
  }

  return flags;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL) return ERROR_M;
  int flags = s21_create_matrix(A->columns, A->rows, result);

  if (!flags) {
    for (int i = 0; i < A->columns; ++i)
      for (int j = 0; j < A->rows; ++j) result->matrix[i][j] = A->matrix[j][i];
  }

  return flags;
}

void s21_find_minor(double **m, double **tmp, int skip_row, int skip_col,
                    int size) {
  for (int i = 0, row = 0; row < size; row++) {
    for (int j = 0, col = 0; col < size; col++) {
      if (row != skip_row && col != skip_col) {
        tmp[i][j] = m[row][col];
        j++;
        if (j == size - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
}

double s21_find_alg(double **m, int size) {
  double res = 0;
  int flags = OK;
  if (size == 1) {
    res = m[0][0];
  }
  matrix_t tmp = {0};
  if (s21_create_matrix(size, size, &tmp)) {
    flags = ERROR_C;
  }
  if (!flags) {
    int sign = 1;
    for (int i = 0; i < size; i++) {
      s21_find_minor(m, tmp.matrix, 0, i, size);
      res += sign * m[0][i] * s21_find_alg(tmp.matrix, size - 1);
      sign = -sign;
    }
  }
  s21_remove_matrix(&tmp);
  return res;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flags = OK;
  if (A == NULL || A->matrix == NULL) {
    flags = ERROR_M;
  }

  if (!flags) {
    if (A->rows != A->columns ||
        s21_create_matrix(A->rows, A->columns, result)) {
      flags = ERROR_C;
    }
  }
  if (!flags) {
    if (A->rows == 1) {
      result->matrix[0][0] = 1;
    } else {
      matrix_t tmp = {0};

      if (s21_create_matrix(A->rows, A->columns, &tmp)) {
        flags = ERROR_C;
      }
      if (!flags) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            s21_find_minor(A->matrix, tmp.matrix, i, j, A->rows);
            int sign = ((i + j) % 2 == 0) ? 1 : -1;
            result->matrix[i][j] = sign * s21_find_alg(tmp.matrix, A->rows - 1);
          }
        }
      }

      s21_remove_matrix(&tmp);
    }
  }
  return flags;
}

int s21_determinant(matrix_t *A, double *result) {
  int flags = OK;
  if (result != NULL) {
    *result = 0.0;
  }

  if (A == NULL || A->matrix == NULL || result == NULL) {
    flags = ERROR_M;
  }

  if (A->rows != A->columns && !flags) {
    flags = ERROR_C;
  }
  if (!flags) {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else {
      *result = s21_find_alg(A->matrix, A->rows);
    }
  }
  return flags;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flags = OK;
  if (A == NULL || A->matrix == NULL) {
    flags = ERROR_M;
  }

  if (A->rows != A->columns && !flags) {
    flags = ERROR_C;
  }
  if (!flags) {
    double d = 0;
    int code = s21_determinant(A, &d);

    if (d == 0 || code) {
      flags = ERROR_C;
    }

    if (!flags) {
      matrix_t tmp = {0};
      if (s21_calc_complements(A, &tmp)) {
        flags = ERROR_C;
      }
      if (!flags) {
        matrix_t transposed = {0};

        if (s21_transpose(&tmp, &transposed) ||
            s21_create_matrix(A->rows, A->rows, result)) {
          flags = ERROR_C;
        }
        if (!flags) {
          for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->rows; j++)
              result->matrix[i][j] = transposed.matrix[i][j] / d;
        }
        s21_remove_matrix(&transposed);
      }
      s21_remove_matrix(&tmp);
    }
  }
  return flags;
}
