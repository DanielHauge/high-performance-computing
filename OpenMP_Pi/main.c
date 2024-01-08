#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[]) {
  double N = 50000.0;
  int clockNow = clock();
  double sum = 0.0;
#pragma omp parallel
  {
    for (int j = 0; j < 10000; j++) {
      sum = 0;
      for (int i = 0; i < N; i++) {
        double x = (i - 0.5) / N;
        double term = 1.0 + x * x;
        sum += 4.0 / term;
      }
      sum = 1 / N * sum;
    }
  }

  int clockEnd = clock();
  float clockTotal = clockEnd - clockNow;
  // compute total time
  float timeTotal = clockTotal / CLOCKS_PER_SEC;
  printf("timeTotal = %f\n", timeTotal);
  printf("sum = %f\n", sum);
  return EXIT_SUCCESS;
}
