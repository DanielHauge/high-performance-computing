#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 500

int main(int argc, char *argv[]) {

  // allocate 1 matrix and 2 vectors
  double *a = (double *)malloc(N * N * sizeof(double));
  double *b = (double *)malloc(N * sizeof(double));
  double *c = (double *)malloc(N * sizeof(double));

  for (int i = 0; i < N; i++) {
    b[i] = i;
    for (int j = 0; j < N; j++) {
      a[i * N + j] = i + j;
    }
  }

  int clockNow = clock();
  for (int j = 0; j < 10000; j++) {
    // matrix vector multiplication
#pragma omp parallel for default(none) shared(a, b, c)
    for (int i = 0; i < N; i++) {
      float sum = 0.0;
      for (int k = 0; k < N; k++) {
        sum += a[i * N + k] * b[k];
      }
#pragma omp critical
      c[i] = sum;
    }
  }

  int clockEnd = clock();
  float clockTotal = clockEnd - clockNow;
  // Compute sum of vector c
  double sum = 0.0;
  for (int i = 0; i < N; i++) {
    sum += c[i];
  }
  printf("sum = %f\n", sum);
  // compute total time
  float timeTotal = clockTotal / CLOCKS_PER_SEC;
  printf("timeTotal = %f\n", timeTotal);
  return EXIT_SUCCESS;
}
