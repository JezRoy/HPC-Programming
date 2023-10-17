#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <stdlib.h>

#define size 10

void multiplyMatrix(int A[size][size], int B[size][size], int C[size][size]) {
    int i, j, k;

    // Parallelize the outer loop; private variables: j, k; shared variables: A, B, C
    #pragma omp parallel for private(j, k) shared (A, B, C)
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            C[i][j] = 0;
            for (k = 0; k < size; k++){
                // Compute the element of C at position (i, j) by summing products of elements from A and B
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(char *name, int M[size][size]) {
    printf("Matrix %c:\n", name);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[size][size];
    int B[size][size];
    int C[size][size];

    // Initialize matrices A and B with random values
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = rand() % 10; // Random value between 0 and 9
            B[i][j] = rand() % 10;
        }
    }

    // Perform matrix multiplication using OpenMP
    multiplyMatrix(A, B, C);

    // Print matrix A
    printMatrix("A", A);

    // Print matrix B
    printMatrix("B", B);

    // Print matrix C
    printMatrix("Result C", C);
}
