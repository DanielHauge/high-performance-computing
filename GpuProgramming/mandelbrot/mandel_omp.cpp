#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
void mandel(int disp_width, int disp_height, int *array, int max_iter) {

  double t = omp_get_wtime();

  double scale_real = 3.5 / (double)disp_width;
  double scale_imag = 3.5 / (double)disp_height;
  int N = disp_width * disp_height;

#pragma omp target data map(tofrom : array[ : N])
  {
    double t = omp_get_wtime();
#pragma omp target teams distribute parallel for map(tofrom : array[ : N])
    for (int i = 0; i < disp_width; i++) {
      int x = ((double)i * scale_real) - 2.25;
      for (int j = 0; j < disp_height; j++) {
        int y = ((double)j * scale_imag) - 1.75;

        int u = 0.0;
        int v = 0.0;
        int u2 = 0.0;
        int v2 = 0.0;
        int iter = 0;

        while (u2 + v2 < 4.0 && iter < max_iter) {
          v = 2 * v * u + y;
          u = u2 - v2 + x;
          u2 = u * u;
          v2 = v * v;
          iter = iter + 1;
        }

        // if we exceed max_iter, reset to zero
        iter = iter == max_iter ? 0 : iter;

        array[i * disp_height + j] = iter;
      }
    }

    printf("w/o transfer time = %3.4f seconds\n", omp_get_wtime() - t);
  }
  printf("w transfer time = %3.4f seconds\n", omp_get_wtime() - t);
}
