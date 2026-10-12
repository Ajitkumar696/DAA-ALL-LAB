
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

void swap(Meeting *a, Meeting *b) {
    Meeting temp = *a;
    *a = *b;
    *b = temp;
}

int compareMeetings(const void *a, const void *b) {
    const Meeting *m1 = (const Meeting *)a;
    const Meeting *m2 = (const Meeting *)b;

    if (m1->start < m2->start)
        return -1;
    if (m1->start > m2->start)
        return 1;
    return 0;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        int temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;

        index = smallest;
    }
}

int extractMin(int heap[], int *size) {
    int minimum = heap[0];

    heap[0] = heap[*size - 1];
    (*size)--;

    if (*size > 0)
        heapifyDown(heap, *size, 0);

    return minimum;
}

int minMeetingRooms(Meeting meetings[], int n) {
    if (n == 0)
        return 0;

    qsort(meetings, n, sizeof(Meeting), compareMeetings);

    int *heap = malloc((size_t)n * sizeof(int));
    if (heap == NULL)
        return -1;

    int size = 0;
    int maxRooms = 0;

    for (int i = 0; i < n; i++) {
        if (size > 0 && heap[0] <= meetings[i].start)
            extractMin(heap, &size);

        heap[size] = meetings[i].end;
        heapifyUp(heap, size);
        size++;

        if (size > maxRooms)
            maxRooms = size;
    }

    free(heap);
    return maxRooms;
}

int main(void) {
    int n;

    printf("Enter number of meetings: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid number of meetings.\n");
        return 1;
    }

    if (n == 0) {
        printf("Minimum number of meeting rooms: 0\n");
        return 0;
    }

    Meeting *meetings = malloc((size_t)n * sizeof(Meeting));
    if (meetings == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter start and end times for each meeting:\n");

    for (int i = 0; i < n; i++) {
        if (scanf("%d %d", &meetings[i].start,
                  &meetings[i].end) != 2 ||
            meetings[i].start >= meetings[i].end) {
            printf("Invalid interval. Start must be less than end.\n");
            free(meetings);
            return 1;
        }
    }

    int rooms = minMeetingRooms(meetings, n);

    if (rooms == -1)
        printf("Memory allocation failed.\n");
    else
        printf("Minimum number of meeting rooms: %d\n", rooms);

    free(meetings);
    return rooms == -1 ? 1 : 0;
}
