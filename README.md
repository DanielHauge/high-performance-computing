# high-performance-computing

Repository for exploring high performance computing

## BLAS (Basic Linear Algebra Subprograms)

CBLAS is a C wrapper library that wraps efficient fortran instructions for basic linear algebra operations.
CBLAS is explored to measure the performance increase from using the wrapper library as opposed to a simple straight forward solution in C.
A ~20x speedup is observed from square matrix matrix multiplications.

## Tuning

Using an optimized data structures can speed up by utilizing caching.
Using struct of arrays has benefits over array of structs, as memory request will have more cache hits.

## Parallel

Using parallel threads is another way to achieve high performant code.
There are many ways to achieve this, one such way is to split the workload and assign threads to compute partial results, and then collect the results.
OpenMP is a library which can be used to make the process of splitting workloads easier.
OpenMP works for C and can for example generically split loop workloads and automatically create a threadpool and assigning/collecting work.
