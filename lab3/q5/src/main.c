#include <stdio.h>

void multiply(int A[4][4], int B[4][4], int C[4][4], int n)
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = 0;

            for (k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

int main()
{
    int A[4][4], B[4][4], C[4][4];
    int n, i, j, k;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter matrix A:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    multiply(A, B, C, n);

    printf("Result:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    return 0;
}