#include <stdio.h>

// Function to find the length of the Longest Increasing Subsequence
int lengthOfLIS(int A[], int n) {
    if (n <= 0) return 0;

    int lis[n];

    // Initialize LIS values for all indexes to 1
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
    }

    // Compute optimized LIS values in bottom-up manner
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    // Pick maximum value among all LIS values
    int maxLIS = 0;
    for (int i = 0; i < n; i++) {
        if (maxLIS < lis[i]) {
            maxLIS = lis[i];
        }
    }

    return maxLIS;
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int A[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int lisLength = lengthOfLIS(A, n);

    printf("Length of Longest Increasing Subsequence: %d\n", lisLength);

    return 0;
}