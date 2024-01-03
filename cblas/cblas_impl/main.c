#include <cblas.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N 5000
#define LOOPS 10

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
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, alpha, A, N,
                B, N, beta, C, N);
  }
  end = clock();
  printf("Time matrix matrix: %f seconds\n",
         (double)(end - start) / CLOCKS_PER_SEC);

  printf("Time matrix matrix: %f seconds per op\n",
         (double)(end - start) / CLOCKS_PER_SEC / LOOPS);

  return EXIT_SUCCESS;
}

