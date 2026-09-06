#include <stdio.h>
#include <stdlib.h>

long long cost = 0;
int reversals = 0;

void reverseRange(int a[], int l, int r) {
    cost += r - l + 1;
    reversals++;
    while (l < r) {
        int t = a[l];
        a[l] = a[r];
        a[r] = t;
        l++;
        r--;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int target = n; target >= 1; target--) {
        int pos = -1;
        for (int i = 0; i < target; i++)
            if (a[i] == target) {
                pos = i;
                break;
            }

        if (pos == target - 1) continue;
        if (pos != 0) reverseRange(a, 0, pos);
        reverseRange(a, 0, target - 1);
    }

    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\nReversals: %d\n", reversals);
    printf("Total reversal cost: %lld\n", cost);

    free(a);
    return 0;
}
