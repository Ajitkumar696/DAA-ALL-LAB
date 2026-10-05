#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

// Function to calculate max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find length of LCS and reconstruct the subsequence string
void findLCS(char X[], char Y[], int m, int n) {
    int L[m + 1][n + 1];

    // Build the DP table in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0'; // Set null terminator for string printing

    // Backtrack from L[m][n] to reconstruct the LCS string
    int i = m, j = n;
    while (i > 0 && j > 0) {
        // If current character in X and Y match, it is part of LCS
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        // If not matching, go in the direction of the larger value
        else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Output results
    printf("Length of Longest Common Subsequence: %d\n", L[m][n]);
    printf("Longest Common Subsequence string: %s\n", lcs);
}

int main() {
    char X[MAX_LEN], Y[MAX_LEN];

    printf("Enter first sequence (X): ");
    if (scanf("%999s", X) != 1) return 1;

    printf("Enter second sequence (Y): ");
    if (scanf("%999s", Y) != 1) return 1;

    int m = strlen(X);
    int n = strlen(Y);

    findLCS(X, Y, m, n);

    return 0;
}
