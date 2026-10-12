
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long ll;

typedef struct {
    ll *arr;
    int size;
    int capacity;
} MaxHeap;

void swap(ll *a, ll *b) {
    ll temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MaxHeap *h, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (h->arr[parent] >= h->arr[i])
            break;

        swap(&h->arr[parent], &h->arr[i]);
        i = parent;
    }
}

void heapifyDown(MaxHeap *h, int i) {
    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < h->size &&
            h->arr[left] > h->arr[largest])
            largest = left;

        if (right < h->size &&
            h->arr[right] > h->arr[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&h->arr[i], &h->arr[largest]);
        i = largest;
    }
}

void insert(MaxHeap *h, ll value) {
    if (h->size == h->capacity)
        return;

    int i = h->size++;
    h->arr[i] = value;
    heapifyUp(h, i);
}

ll extractMax(MaxHeap *h) {
    ll maximum = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    if (h->size > 0)
        heapifyDown(h, 0);

    return maximum;
}

ll peekMax(MaxHeap *h) {
    return h->arr[0];
}

int main(void) {
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    ll *values = malloc((size_t)n * sizeof(ll));
    ll *heapArray = malloc((size_t)n * sizeof(ll));

    if (values == NULL || heapArray == NULL) {
        printf("Memory allocation failed.\n");
        free(values);
        free(heapArray);
        return 1;
    }

    printf("Enter %d positive integers: ", n);

    ll minimum = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        if (scanf("%lld", &values[i]) != 1 || values[i] <= 0) {
            printf("Invalid input. Enter positive integers only.\n");
            free(values);
            free(heapArray);
            return 1;
        }

        if (values[i] % 2 != 0)
            values[i] *= 2;

        if (values[i] < minimum)
            minimum = values[i];

        heapArray[i] = values[i];
    }

    MaxHeap heap = {heapArray, 0, n};

    for (int i = 0; i < n; i++)
        insert(&heap, values[i]);

    ll answer = peekMax(&heap) - minimum;

    while (peekMax(&heap) % 2 == 0) {
        ll maximum = extractMax(&heap);
        ll reduced = maximum / 2;

        if (reduced < minimum)
            minimum = reduced;

        insert(&heap, reduced);

        ll deviation = peekMax(&heap) - minimum;

        if (deviation < answer)
            answer = deviation;
    }

    printf("Minimum possible deviation: %lld\n", answer);

    free(values);
    free(heapArray);
    return 0;
}
