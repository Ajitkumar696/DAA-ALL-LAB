
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000
#define ALPHABET 256

typedef struct {
    unsigned char ch;
    int freq;
} Node;

typedef struct {
    Node data[ALPHABET];
    int size;
} MaxHeap;

typedef struct {
    unsigned char ch;
    int freq;
    int release_pos;
} WaitingItem;

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

int higher_priority(Node a, Node b) {
    if (a.freq != b.freq)
        return a.freq > b.freq;

    return a.ch < b.ch;
}

void push(MaxHeap *h, Node value) {
    int i = h->size++;
    h->data[i] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (!higher_priority(h->data[i], h->data[parent]))
            break;

        swap(&h->data[i], &h->data[parent]);
        i = parent;
    }
}

Node pop(MaxHeap *h) {
    Node result = h->data[0];
    h->data[0] = h->data[--h->size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int best = i;

        if (left < h->size &&
            higher_priority(h->data[left], h->data[best]))
            best = left;

        if (right < h->size &&
            higher_priority(h->data[right], h->data[best]))
            best = right;

        if (best == i)
            break;

        swap(&h->data[i], &h->data[best]);
        i = best;
    }

    return result;
}

int main(void) {
    char s[MAX_LEN + 1];
    char result[MAX_LEN + 1];
    int freq[ALPHABET] = {0};
    int K;

    MaxHeap heap = {{{0, 0}}, 0};
    WaitingItem waiting[MAX_LEN];

    int front = 0, rear = 0;
    int n;

    printf("Enter the string: ");

    if (scanf("%1000s", s) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter K: ");

    if (scanf("%d", &K) != 1 || K < 0) {
        printf("Invalid K.\n");
        return 1;
    }

    n = (int)strlen(s);

    /* If K is 0 or 1, the original string is valid. */
    if (K <= 1) {
        printf("Reorganized string: %s\n", s);
        return 0;
    }

    for (int i = 0; i < n; i++)
        freq[(unsigned char)s[i]]++;

    /* Build the max-heap from distinct characters. */
    for (int i = 0; i < ALPHABET; i++) {
        if (freq[i] > 0) {
            Node node;
            node.ch = (unsigned char)i;
            node.freq = freq[i];
            push(&heap, node);
        }
    }

    for (int pos = 0; pos < n; pos++) {
        /* Release characters whose cooldown has expired. */
        while (front < rear &&
               waiting[front].release_pos <= pos) {
            Node node;
            node.ch = waiting[front].ch;
            node.freq = waiting[front].freq;
            push(&heap, node);
            front++;
        }

        /* No character is available: impossible arrangement. */
        if (heap.size == 0) {
            printf("Reorganized string: \"\"\n");
            return 0;
        }

        Node current = pop(&heap);
        result[pos] = (char)current.ch;
        current.freq--;

        /* Prevent reuse until K positions have passed. */
        if (current.freq > 0) {
            waiting[rear].ch = current.ch;
            waiting[rear].freq = current.freq;
            waiting[rear].release_pos = pos + K;
            rear++;
        }
    }

    result[n] = '\0';

    printf("Reorganized string: %s\n", result);
    return 0;
}
