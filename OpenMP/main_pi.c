#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 500000

int main(int argc, char *argv[]) {
  // get wall clock with timespec_get
#if defined(_OPENMP)
  double start_time = omp_get_wtime();
#else
  double start_time = clock();
#endif
  double sum = 0.0;
  for (int j = 0; j < 10000; j++) {
    sum = 0;
    // CALCULATE PI
#pragma omp parallel for default(none) reduction(+ : sum)
    for (int i = 0; i < N; i++) {
      double x = (i - 0.5) / N;
      double term = 1.0 + x * x;
      sum += 4.0 / term;
    }
    sum = 1.0 / N * sum;
  }

#if defined(_OPENMP)
  double end_time = omp_get_wtime();
#else
  double end_time = clock();
#endif

  double timeTotal = end_time - start_time;

  printf("timeTotal = %f\n", timeTotal);
  printf("sum = %f\n", sum);
  return EXIT_SUCCESS;
}
