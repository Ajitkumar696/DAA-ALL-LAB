
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

long long weight[MAX];
long long prefix[MAX + 1];
long long dp[MAX][MAX];
int split[MAX][MAX];

long long rangeSum(int i, int j) {
    return prefix[j + 1] - prefix[i];
}

void printTree(int i, int j) {
    if (i == j) {
        printf("L%d", i + 1);
        return;
    }

    int k = split[i][j];

    printf("(");
    printTree(i, k);
    printf(", ");
    printTree(k + 1, j);
    printf(")");
}

void printDepths(int i, int j, int depth) {
    if (i == j) {
        printf("Leaf %d: weight = %lld, depth = %d, "
               "cost = %lld\n",
               i + 1, weight[i], depth,
               weight[i] * depth);
        return;
    }

    int k = split[i][j];
    printDepths(i, k, depth + 1);
    printDepths(k + 1, j, depth + 1);
}

int main(void) {
    int n;

    printf("Enter number of weights (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of weights.\n");
        return 1;
    }

    printf("Enter %d positive weights in order: ", n);

    for (int i = 0; i < n; i++) {
        if (scanf("%lld", &weight[i]) != 1 ||
            weight[i] <= 0) {
            printf("Weights must be positive integers.\n");
            return 1;
        }

        prefix[i + 1] = prefix[i] + weight[i];
        dp[i][i] = 0;
        split[i][i] = i;
    }

    /* Consider intervals of increasing length. */
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX / 4;

            for (int k = i; k < j; k++) {
                long long candidate =
                    dp[i][k] + dp[k + 1][j]
                    + rangeSum(i, j);

                if (candidate < dp[i][j]) {
                    dp[i][j] = candidate;
                    split[i][j] = k;
                }
            }
        }
    }

    printf("\nOptimal alphabetic tree:\n");
    printTree(0, n - 1);

    printf("\n\nMinimum weighted path length: %lld\n",
           dp[0][n - 1]);

    printf("\nLeaf depths and individual costs:\n");
    printDepths(0, n - 1, 0);

    return 0;
}
