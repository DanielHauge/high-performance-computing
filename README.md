# high-performance-computing

Repository for exploring high performance computing

## BLAS (Basic Linear Algebra Subprograms)

CBLAS is a C wrapper library that wraps efficient fortran instructions for basic linear algebra operations.
CBLAS is explored to measure the performance increase from using the wrapper library as opposed to a simple straight forward solution in C.
A ~20x speedup is observed from square matrix matrix multiplications.

## Tuning

Using an optimized data structures can speed up by utilizing caching.
Using struct of arrays has benefits over array of structs, as memory request will have more cache hits.
