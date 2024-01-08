#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50000

int main(int argc, char *argv[]) {

  int clockNow = clock();
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

  int clockEnd = clock();
  float clockTotal = clockEnd - clockNow;
  // compute total time
  float timeTotal = clockTotal / CLOCKS_PER_SEC;
  printf("timeTotal = %f\n", timeTotal);
  printf("sum = %f\n", sum);
  return EXIT_SUCCESS;
}
