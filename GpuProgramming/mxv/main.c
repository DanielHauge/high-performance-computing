#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define ITER 500
#define N 5000
#define NN 5000 * 5000
double **dmalloc_2d(int m, int n) {
  if (m <= 0 || n <= 0)
    return NULL;
  double **A = (double **)malloc(m * sizeof(double *));
  if (A == NULL)
    return NULL;
  A[0] = (double *)malloc(m * n * sizeof(double));
  if (A[0] == NULL) {
    free(A);
    return NULL;
  }
  for (int i = 1; i < m; i++)
    A[i] = A[0] + i * n;
  return A;
}

// matrix vector
void matrix_vector(double **matrix, double *vector, double *result) {
  double t = omp_get_wtime();
#pragma omp taget data map(to : matrix[0 : N / 2][0 : N / 2],                  \
                               vector[0 : N / 2])                              \
    map(from : result[0 : N / 2])
  {
    double t = omp_get_wtime();

#pragma omp target teams distribute parallel for nowait num_teams(N / 2)       \
    thread_limit(1) device(0)                                                  \
    map(to : matrix[0 : N / 2][0 : N / 2], vector[0 : N / 2])                  \
    map(from : result[0 : N / 2])
    for (int i = 0; i < N / 2; i++) {
      for (int j = 0; j < N / 2; j++) {
        result[i] += matrix[i][j] * vector[j];
      }
    }
    printf("1. w/o allo: %f\n", omp_get_wtime() - t);
  }
  printf("1. w allo: %f\n", omp_get_wtime() - t);
  double t2 = omp_get_wtime();
#pragma omp target data map(to : matrix[N / 2 : N / 2][0 : N / 2],             \
                                vector[0 : N / 2])
  {
    double t = omp_get_wtime();

#pragma omp target teams distribute parallel for nowait num_teams(N / 2)       \
    thread_limit(1) device(1)                                                  \
    map(to : matrix[N / 2 : N / 2][N / 2 : N / 2], vector[N / 2 : N / 2])      \
    map(from : result[N / 2 : N / 2])
    for (int i = N / 2; i < N; i++) {
      for (int j = N / 2; j < N; j++) {
        result[i] += matrix[i][j] * vector[j];
      }
    }
    printf("2. w/o allo: %f\n", omp_get_wtime() - t);
  }
  printf("2. w allo: %f\n", omp_get_wtime() - t2);

#pragma omp taskwait
}

int main(int argc, char *argv[]) {
  // Allocate matrix and vector
  double **matrix = dmalloc_2d(N, N);
  double *vector = (double *)malloc(N * sizeof(double));
  double *result = (double *)malloc(N * sizeof(double));

  // Initialize matrix and vector
  for (int i = 0; i < N; i++) {
    vector[i] = i;
    result[i] = 0;
    for (int j = 0; j < N; j++) {
      matrix[i][j] = (double)i + j;
    }
  }

  for (int i = 0; i < ITER; i++) {
    matrix_vector(matrix, vector, result);
  }

  // Print result
  double d = 0;
  for (int i = 0; i < N; i++) {
    d += result[i];
  }
  printf("%f", d);
  return EXIT_SUCCESS;
}
