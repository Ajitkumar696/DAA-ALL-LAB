#include <stdio.h>

// Function to find the total number of ways/combinations to form target amount V
long long countWays(int C[], int n, int V) {
    // dp[i] will store the number of ways to form amount i
    long long dp[V + 1];

    // Initialize all dp values to 0
    for (int i = 0; i <= V; i++) {
        dp[i] = 0;
    }

    // Base Case: There is 1 way to make amount 0 (by using 0 coins)
    dp[0] = 1;

    // Loop through each coin first to avoid permutations and count only unique combinations
    for (int i = 0; i < n; i++) {
        for (int j = C[i]; j <= V; j++) {
            dp[j] += dp[j - C[i]];
        }
    }

    return dp[V];
}

int main() {
    int n, V;

    printf("Enter the number of coin denominations: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of coins.\n");
        return 1;
    }

    int C[n];
    printf("Enter the coin denominations: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &C[i]);
    }

    printf("Enter the target amount V: ");
    scanf("%d", &V);

    if (V < 0) {
        printf("Invalid target amount.\n");
        return 1;
    }

    long long ways = countWays(C, n, V);

    printf("Total number of ways to make amount %d: %lld\n", V, ways);

    return 0;
}