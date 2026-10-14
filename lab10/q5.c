#include <stdio.h>

// Function to find the maximum sum of a strictly increasing subsequence
int maxSumIS(int A[], int n) {
    if (n <= 0) return 0;

    int msis[n];

    // Initialize MSIS values with the original array values
    for (int i = 0; i < n; i++) {
        msis[i] = A[i];
    }

    // Compute maximum sum increasing subsequence values bottom-up
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j] && msis[i] < msis[j] + A[i]) {
                msis[i] = msis[j] + A[i];
            }
        }
    }

    // Pick maximum value among all msis values
    int maxSum = 0;
    for (int i = 0; i < n; i++) {
        if (maxSum < msis[i]) {
            maxSum = msis[i];
        }
    }

    return maxSum;
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int A[n];
    printf("Enter %d positive integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int maxSum = maxSumIS(A, n);

    printf("Maximum sum of an increasing subsequence: %d\n", maxSum);

    return 0;
}