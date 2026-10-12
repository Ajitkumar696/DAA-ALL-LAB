
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100000

typedef struct {
    long long heap[MAX];
    int size;
} MinHeap;

void swap(long long *a, long long *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

void insert(MinHeap *h, long long value) {
    int i = h->size++;
    h->heap[i] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (h->heap[parent] <= h->heap[i])
            break;

        swap(&h->heap[parent], &h->heap[i]);
        i = parent;
    }
}

long long extract_min(MinHeap *h) {
    long long result = h->heap[0];
    h->heap[0] = h->heap[--h->size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < h->size &&
            h->heap[left] < h->heap[smallest])
            smallest = left;

        if (right < h->size &&
            h->heap[right] < h->heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&h->heap[i], &h->heap[smallest]);
        i = smallest;
    }

    return result;
}

int main(void) {
    MinHeap h = {{0}, 0};
    int n;
    long long length;
    long long total_cost = 0;

    printf("Enter number of sticks (1-%d): ", MAX);

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of sticks.\n");
        return 1;
    }

    printf("Enter the lengths of the sticks:\n");

    for (int i = 0; i < n; i++) {
        if (scanf("%lld", &length) != 1 || length < 0) {
            printf("Invalid stick length.\n");
            return 1;
        }

        insert(&h, length);
    }

    printf("\nConnection steps:\n");

    int step = 1;

    while (h.size > 1) {
        long long x = extract_min(&h);
        long long y = extract_min(&h);

        /* Check for overflow in x + y. */
        if (x > LLONG_MAX - y) {
            printf("Error: stick length overflow.\n");
            return 1;
        }

        long long cost = x + y;

        /* Check for overflow in total cost. */
        if (total_cost > LLONG_MAX - cost) {
            printf("Error: total cost overflow.\n");
            return 1;
        }

        total_cost += cost;

        printf("Step %d: Connect %lld and %lld, "
               "cost = %lld\n",
               step++, x, y, cost);

        insert(&h, cost);
    }

    printf("\nMinimum total connection cost = %lld\n",
           total_cost);

    return 0;
}
