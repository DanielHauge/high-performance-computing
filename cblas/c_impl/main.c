#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5000
#define LOOPS 10

void matrix_matrix(double *A, double *B, double *C) {
  for (int i = 0; i < N; i++) {
    for (int k = 0; k < N; k++) {
      double temp = 0.0;
      for (int j = 0; j < N; j++) {
        temp += A[i * N + j] * B[j * N + k];
      }
      C[i * N + k] = temp;
    }
  }
}

int main(int argc, char *argv[]) {
  printf("Hello world");

  double *A = (double *)malloc(N * N * sizeof(double));
  double *B = (double *)malloc(N * N * sizeof(double));
  double *C = (double *)malloc(N * N * sizeof(double));
  double alpha = 1.0;
  double beta = 0.0;

  for (int i = 0; i < N * N; i++) {
    A[i] = i;
    B[i] = i;
  }
  int start, end;

  printf("%i x %i matrices/vectors and %i loops\n", N, N, LOOPS);

  start = clock();
  for (int i = 0; i < LOOPS; i++) {
    matrix_matrix(A, B, C);
  }
  end = clock();
  printf("Time matrix matrix: %f seconds\n",
         (double)(end - start) / CLOCKS_PER_SEC);

  printf("Time matrix matrix: %f seconds per op\n",
         (double)(end - start) / CLOCKS_PER_SEC / LOOPS);

  return EXIT_SUCCESS;
}
