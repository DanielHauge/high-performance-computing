#include <stdio.h>
#include <stdlib.h>
#define N 1000

// matrix vector
void matrix_vector(int *matrix, int *vector, int *result, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    result[i] = 0;
    for (j = 0; j < n; j++) {
      result[i] += matrix[i * n + j] * vector[j];
    }
  }
}

int main(int argc, char *argv[]) {
  // Allocate matrix and vector
  int *matrix = (int *)malloc(N * N * sizeof(int));
  int *vector = (int *)malloc(N * sizeof(int));
  int *result = (int *)malloc(N * sizeof(int));

  // Initialize matrix and vector
  for (int i = 0; i < N; i++) {
    vector[i] = i;
    for (int j = 0; j < N; j++) {
      matrix[i * N + j] = i + j;
    }
  }

  matrix_vector(matrix, vector, result, N);

  // Print result
  for (int i = 0; i < N; i++) {
    printf("%d\n", result[i]);
  }
  return EXIT_SUCCESS;
}
