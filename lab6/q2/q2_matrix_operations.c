#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-9

void addMatrices(int n, double A[n][n], double B[n][n], double C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void multiplyMatrices(int n, double A[n][n], double B[n][n], double C[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

int isZeroMatrix(int n, double A[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (fabs(A[i][j]) > EPS)
                return 0;

    return 1;
}

int isSymmetric(int n, double A[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (fabs(A[i][j] - A[j][i]) > EPS)
                return 0;

    return 1;
}

double determinant(int n, double A[n][n]) {
    if (n == 1)
        return A[0][0];

    if (n == 2)
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];

    double det = 0;

    double **M = malloc((n - 1) * sizeof(double *));

    for (int i = 0; i < n - 1; i++)
        M[i] = malloc((n - 1) * sizeof(double));

    for (int col = 0; col < n; col++) {

        for (int i = 1; i < n; i++) {
            int x = 0;

            for (int j = 0; j < n; j++) {
                if (j != col)
                    M[i - 1][x++] = A[i][j];
            }
        }

        double minorDet = 0;

        if (n - 1 == 1) {
            minorDet = M[0][0];
        } else if (n - 1 == 2) {
            minorDet =
                M[0][0] * M[1][1] -
                M[0][1] * M[1][0];
        } else {
            double **N = malloc((n - 2) * sizeof(double *));

            for (int i = 0; i < n - 2; i++)
                N[i] = malloc((n - 2) * sizeof(double));

            for (int c = 0; c < n - 1; c++) {

                for (int i = 1; i < n - 1; i++) {
                    int x = 0;

                    for (int j = 0; j < n - 1; j++) {
                        if (j != c)
                            N[i - 1][x++] = M[i][j];
                    }
                }

                double subDet = 0;

                if (n - 2 == 1) {
                    subDet = N[0][0];
                }

                if (n - 2 == 2) {
                    subDet =
                        N[0][0] * N[1][1] -
                        N[0][1] * N[1][0];
                }

                if (c % 2 == 0)
                    minorDet += M[0][c] * subDet;
                else
                    minorDet -= M[0][c] * subDet;
            }

            for (int i = 0; i < n - 2; i++)
                free(N[i]);

            free(N);
        }

        if (col % 2 == 0)
            det += A[0][col] * minorDet;
        else
            det -= A[0][col] * minorDet;
    }

    for (int i = 0; i < n - 1; i++)
        free(M[i]);

    free(M);

    return det;
}

void transpose(int n, double A[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}

void printMatrix(int n, double A[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%.2lf ", A[i][j]);
        printf("\n");
    }
}

void eigenValues2x2(double A[2][2]) {
    double trace = A[0][0] + A[1][1];

    double det =
        A[0][0] * A[1][1] -
        A[0][1] * A[1][0];

    double discriminant = trace * trace - 4 * det;

    if (discriminant < -EPS) {
        printf("Eigenvalues are complex.\n");
        return;
    }

    if (discriminant < 0)
        discriminant = 0;

    double root = sqrt(discriminant);

    double lambda1 = (trace + root) / 2;
    double lambda2 = (trace - root) / 2;

    printf("Eigenvalue 1: %.4lf\n", lambda1);
    printf("Eigenvalue 2: %.4lf\n", lambda2);

    double v1x, v1y, v2x, v2y;

    if (fabs(A[0][1]) > EPS) {
        v1x = A[0][1];
        v1y = lambda1 - A[0][0];

        v2x = A[0][1];
        v2y = lambda2 - A[0][0];
    } else if (fabs(A[1][0]) > EPS) {
        v1x = lambda1 - A[1][1];
        v1y = A[1][0];

        v2x = lambda2 - A[1][1];
        v2y = A[1][0];
    } else {
        v1x = 1;
        v1y = 0;

        v2x = 0;
        v2y = 1;
    }

    printf("Eigenvector 1: [%.4lf, %.4lf]\n", v1x, v1y);
    printf("Eigenvector 2: [%.4lf, %.4lf]\n", v2x, v2y);
}

int main() {
    int n;

    printf("Enter matrix size: ");
    scanf("%d", &n);

    double A[n][n];
    double B[n][n];
    double C[n][n];

    printf("Enter Matrix A:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    printf("Enter Matrix B:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &B[i][j]);

    printf("\nMatrix Addition:\n");
    addMatrices(n, A, B, C);
    printMatrix(n, C);

    printf("\nMatrix Multiplication:\n");
    multiplyMatrices(n, A, B, C);
    printMatrix(n, C);

    printf("\nZero Matrix Check:\n");

    if (isZeroMatrix(n, A))
        printf("Matrix A is a zero matrix.\n");
    else
        printf("Matrix A is not a zero matrix.\n");

    printf("\nSymmetric Matrix Check:\n");

    if (isSymmetric(n, A))
        printf("Matrix A is symmetric.\n");
    else
        printf("Matrix A is not symmetric.\n");

    printf("\nDeterminant of Matrix A:\n");
    printf("%.4lf\n", determinant(n, A));

    printf("\nTranspose of Matrix A:\n");
    transpose(n, A);
    printMatrix(n, A);

    if (n == 2) {
        double E[2][2];

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                E[i][j] = A[i][j];

        printf("\nEigenvalues and Eigenvectors:\n");
        eigenValues2x2(E);
    } else {
        printf("\nEigenvalues and Eigenvectors:\n");
        printf("Implemented for 2 x 2 matrices.\n");
    }

    return 0;
}