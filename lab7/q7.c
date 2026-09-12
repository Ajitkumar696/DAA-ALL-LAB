#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printParenthesis(int i, int j, int n, int *s, char *name) {
    if (i == j) {
        printf("%c", (*name)++);
        return;
    }
    printf("(");
    printParenthesis(i, *((s + i * (n + 1)) + j), n, s, name);
    printParenthesis(*((s + i * (n + 1)) + j) + 1, j, n, s, name);
    printf(")");
}

void matrixChainOrder(int p[], int num_matrices) {
    int n = num_matrices;
    int m[n + 1][n + 1];
    int s[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum scalar multiplications: %d\n", m[1][n]);
    printf("Optimal Parenthesization: ");
    char name = 'A';
    printParenthesis(1, n, n, (int *)s, &name);
    printf("\n");
}

int main(void) {
    int dimensions[] = {40, 20, 30, 10, 30};
    int num_matrices = (sizeof(dimensions) / sizeof(dimensions[0])) - 1;
    
    matrixChainOrder(dimensions, num_matrices);
    return 0;
}