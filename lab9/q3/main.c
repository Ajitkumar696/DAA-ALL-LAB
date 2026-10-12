
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    long long distance;
    long long fuel;
} Station;

typedef struct {
    long long heap[MAX];
    int size;
} MaxHeap;

void swap(long long *a, long long *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

void push(MaxHeap *h, long long fuel) {
    int i = h->size++;
    h->heap[i] = fuel;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (h->heap[parent] >= h->heap[i])
            break;

        swap(&h->heap[parent], &h->heap[i]);
        i = parent;
    }
}

long long pop(MaxHeap *h) {
    long long result = h->heap[0];
    h->heap[0] = h->heap[--h->size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < h->size &&
            h->heap[left] > h->heap[largest])
            largest = left;

        if (right < h->size &&
            h->heap[right] > h->heap[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&h->heap[i], &h->heap[largest]);
        i = largest;
    }

    return result;
}

int compare_stations(const void *a, const void *b) {
    const Station *x = (const Station *)a;
    const Station *y = (const Station *)b;

    if (x->distance < y->distance) return -1;
    if (x->distance > y->distance) return 1;
    return 0;
}

int main(void) {
    Station stations[MAX];
    MaxHeap heap = {{0}, 0};

    int n;
    long long D, F;

    printf("Enter target distance D and initial fuel F: ");

    if (scanf("%lld %lld", &D, &F) != 2 ||
        D < 0 || F < 0) {
        printf("Invalid target distance or initial fuel.\n");
        return 1;
    }

    printf("Enter number of fuel stations: ");

    if (scanf("%d", &n) != 1 || n < 0 || n > MAX) {
        printf("Invalid number of stations.\n");
        return 1;
    }

    printf("Enter each station's distance and fuel amount:\n");

    for (int i = 0; i < n; i++) {
        if (scanf("%lld %lld",
                  &stations[i].distance,
                  &stations[i].fuel) != 2 ||
            stations[i].distance < 0 ||
            stations[i].distance > D ||
            stations[i].fuel < 0) {
            printf("Invalid station data.\n");
            return 1;
        }
    }

    qsort(stations, n, sizeof(Station), compare_stations);

    long long reachable = F;
    int i = 0;
    int stops = 0;

    while (reachable < D) {
        /* Add all stations that can currently be reached. */
        while (i < n && stations[i].distance <= reachable) {
            if (stations[i].fuel > 0)
                push(&heap, stations[i].fuel);
            i++;
        }

        /* No reachable station can provide more fuel. */
        if (heap.size == 0) {
            printf("\nTarget cannot be reached.\n");
            return 0;
        }

        long long best_fuel = pop(&heap);

        if (reachable > D - best_fuel)
            reachable = D;
        else
            reachable += best_fuel;

        stops++;

        printf("Stop %d: Refuel amount = %lld, "
               "reachable distance = %lld\n",
               stops, best_fuel, reachable);
    }

    printf("\nMinimum refuelling stops = %d\n", stops);

    return 0;
}
