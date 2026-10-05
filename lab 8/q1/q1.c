#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of coins needed to make amount V
int minCoins(int C[], int n, int V) {
    // dp[i] will store the minimum coins needed for amount i
    int dp[V + 1];

    // Base case: 0 coins are needed to make amount 0
    dp[0] = 0;

    // Initialize all dp values as INT_MAX (infinity)
    for (int i = 1; i <= V; i++) {
        dp[i] = INT_MAX;
    }

    // Compute minimum coins required for all values from 1 to V
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < n; j++) {
            if (C[j] <= i) {
                int subResult = dp[i - C[j]];
                if (subResult != INT_MAX && subResult + 1 < dp[i]) {
                    dp[i] = subResult + 1;
                }
            }
        }
    }

    // If dp[V] is still INT_MAX, it means amount V cannot be formed
    if (dp[V] == INT_MAX) {
        return -1;
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

    int result = minCoins(C, n, V);

    if (result == -1) {
        printf("Target amount %d cannot be formed with the given coins.\n", V);
    } else {
        printf("Minimum coins required to make amount %d: %d\n", V, result);
    }

    return 0;
}