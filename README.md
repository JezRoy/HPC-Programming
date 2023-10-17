# HPC-Programming

A place where I work on general HPC Projects and run them on a GPU of some sort.

1) Matrix Multiplication

Matrix multiplication is a problem suitable for parallelization using both OpenMP (OMP) and MPI (Message Passing Interface) due to its inherent parallel nature. When multiplying two matrices, each element of the resulting matrix is independent of the others, making it a good candidate for parallel computation. OpenMP is suitable for shared-memory parallelism on multi-core systems, while MPI is suitable for distributed-memory parallelism, often used on clusters or supercomputers.
