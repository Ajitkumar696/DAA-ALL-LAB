#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int maximum(int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx) mx = a[i];
    return mx;
}

void firstSecondLargest(int a[], int n, int *first, int *second) {
    *first = *second = -2147483648;
    for (int i = 0; i < n; i++) {
        if (a[i] > *first) {
            *second = *first;
            *first = a[i];
        } else if (a[i] > *second && a[i] != *first) {
            *second = a[i];
        }
    }
}

double mean(int a[], int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    return (double)sum / n;
}

int cmp(const void *x, const void *y) {
    return (*(int *)x - *(int *)y);
}

double median(int a[], int n) {
    int *b = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) b[i] = a[i];
    qsort(b, n, sizeof(int), cmp);
    double result;
    if (n % 2) result = b[n / 2];
    else result = (b[n / 2 - 1] + b[n / 2]) / 2.0;
    free(b);
    return result;
}

double standardDeviation(int a[], int n) {
    double m = mean(a, n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double d = a[i] - m;
        sum += d * d;
    }
    return sqrt(sum / n);
}

int mode(int a[], int n) {
    int best = a[0], bestCount = 1;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (a[j] == a[i]) count++;
        if (count > bestCount) {
            bestCount = count;
            best = a[i];
        }
    }
    return best;
}

int removeDuplicates(int a[], int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < k; j++) {
            if (a[j] == a[i]) {
                found = 1;
                break;
            }
        }
        if (!found) a[k++] = a[i];
    }
    return k;
}

void reverseArray(int a[], int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}

void partitionArray(int a[], int n, int pivot) {
    int left = 0, right = n - 1;
    while (left <= right) {
        while (left <= right && a[left] < pivot) left++;
        while (left <= right && a[right] >= pivot) right--;
        if (left < right) {
            int t = a[left];
            a[left] = a[right];
            a[right] = t;
            left++;
            right--;
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Maximum: %d\n", maximum(a, n));

    int first, second;
    firstSecondLargest(a, n, &first, &second);
    printf("First largest: %d\n", first);
    if (second == -2147483648)
        printf("Second largest: Not available\n");
    else
        printf("Second largest: %d\n", second);

    printf("Mean: %.2f\n", mean(a, n));
    printf("Median: %.2f\n", median(a, n));
    printf("Standard deviation: %.2f\n", standardDeviation(a, n));
    printf("Mode: %d\n", mode(a, n));

    int *b = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) b[i] = a[i];
    int unique = removeDuplicates(b, n);
    printf("After removing duplicates: ");
    printArray(b, unique);

    for (int i = 0; i < n; i++) b[i] = a[i];
    reverseArray(b, n);
    printf("Reversed array: ");
    printArray(b, n);

    int pivot;
    printf("Enter pivot: ");
    scanf("%d", &pivot);
    for (int i = 0; i < n; i++) b[i] = a[i];
    partitionArray(b, n, pivot);
    printf("Partitioned array: ");
    printArray(b, n);

    free(a);
    free(b);
    return 0;
}
