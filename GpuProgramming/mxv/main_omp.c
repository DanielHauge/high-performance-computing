#include <stdio.h>
#include <stdlib.h>
#define ITER 500
#define N 5000

double** dmalloc_2d(int m, int n) { if (m <= 0 || n <= 0) return NULL; double **A = (double**)malloc(m * sizeof(double *)); if (A == NULL) return NULL; A[0] = (double *)malloc(m*n*sizeof(double)); if (A[0] == NULL) { free(A); return NULL; } for (int i = 1; i < m; i++) A[i] = A[0] + i * n; return A; }


// matrix vector
void matrix_vector(double **matrix, double *vector, double *result, int n) {
//#pragma omp parallel for
	int i,j;
#pragma omp parallel for default(none) shared(matrix,vector,n, result) private(i,j)
  for (i = 0; i < n; i++) {
	  double gg = 0;
    for (j = 0; j < n; j++) {
       gg+= matrix[i][j] * vector[j];
    }

	#pragma omp critical
    result[i] += gg;
  }
}

int main(int argc, char *argv[]) {
  // Allocate matrix and vector
  double **matrix = dmalloc_2d(N,N);
  double *vector = (double *)malloc(N * sizeof(double));
  double *result = (double *)malloc(N * sizeof(double));


  // Initialize matrix and vector
  for (int i = 0; i < N; i++) {
    vector[i] = i;
    result[i] = 0;
    for (int j = 0; j < N; j++) {
	    matrix[i][j] = (double)i+j;
    }
  }

  for (int i = 0; i < ITER; i++){
  	matrix_vector(matrix, vector, result, N);
  }



  // Print result
  double d = 0;
	for (int i = 0; i < N; i++){
	d += result[i];	
	}
	printf("%f", d);
  return EXIT_SUCCESS;
}
