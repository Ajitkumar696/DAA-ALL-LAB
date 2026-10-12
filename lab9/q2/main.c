
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 100
#define TOTAL (2 * MAX)

typedef struct {
    long long frequency;
    int left;
    int right;
    char symbol;
    char min_symbol;
    int is_leaf;
} Node;

typedef struct {
    int data[TOTAL];
    int size;
} MinHeap;

typedef struct {
    char symbol;
    int length;
    char code[MAX + 1];
} Code;

Node nodes[TOTAL];
int node_count = 0;

/* Deterministic tie-breaking for equal frequencies. */
int smaller_node(int a, int b) {
    if (nodes[a].frequency != nodes[b].frequency)
        return nodes[a].frequency < nodes[b].frequency;

    if (nodes[a].min_symbol != nodes[b].min_symbol)
        return nodes[a].min_symbol < nodes[b].min_symbol;

    return a < b;
}

void swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heap_push(MinHeap *heap, int value) {
    int i = heap->size++;
    heap->data[i] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (!smaller_node(heap->data[i], heap->data[parent]))
            break;

        swap_int(&heap->data[i], &heap->data[parent]);
        i = parent;
    }
}

int heap_pop(MinHeap *heap) {
    int result = heap->data[0];
    heap->data[0] = heap->data[--heap->size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap->size &&
            smaller_node(heap->data[left],
                         heap->data[smallest]))
            smallest = left;

        if (right < heap->size &&
            smaller_node(heap->data[right],
                         heap->data[smallest]))
            smallest = right;

        if (smallest == i)
            break;

        swap_int(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }

    return result;
}

void get_lengths(int index, int depth, Code codes[],
                 int *count) {
    if (nodes[index].is_leaf) {
        codes[*count].symbol = nodes[index].symbol;

        /* A single-symbol alphabet gets code 0. */
        codes[*count].length = (depth == 0) ? 1 : depth;

        codes[*count].code[0] = '\0';
        (*count)++;
        return;
    }

    get_lengths(nodes[index].left, depth + 1,
                codes, count);
    get_lengths(nodes[index].right, depth + 1,
                codes, count);
}

int compare_codes(const void *a, const void *b) {
    const Code *x = (const Code *)a;
    const Code *y = (const Code *)b;

    if (x->length != y->length)
        return x->length - y->length;

    return (unsigned char)x->symbol -
           (unsigned char)y->symbol;
}

/* Increment a binary code of the specified length. */
int increment_code(char code[], int length) {
    int i = length - 1;

    while (i >= 0 && code[i] == '1') {
        code[i] = '0';
        i--;
    }

    if (i < 0)
        return 0;

    code[i] = '1';
    return 1;
}

int main(void) {
    int n;
    char input_symbols[MAX];
    long long input_freq[MAX];
    long long total_frequency = 0;
    MinHeap heap = {{0}, 0};
    Code codes[MAX];
    int code_count = 0;

    printf("Enter number of symbols (1-%d): ", MAX);

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of symbols.\n");
        return 1;
    }

    printf("Enter each symbol and its positive frequency:\n");

    for (int i = 0; i < n; i++) {
        if (scanf(" %c %lld",
                  &input_symbols[i],
                  &input_freq[i]) != 2 ||
            input_freq[i] <= 0) {
            printf("Invalid symbol or frequency.\n");
            return 1;
        }

        for (int j = 0; j < i; j++) {
            if (input_symbols[j] == input_symbols[i]) {
                printf("Duplicate symbols are not allowed.\n");
                return 1;
            }
        }

        if (total_frequency > LLONG_MAX - input_freq[i]) {
            printf("Total frequency is too large.\n");
            return 1;
        }

        total_frequency += input_freq[i];

        nodes[node_count].frequency = input_freq[i];
        nodes[node_count].symbol = input_symbols[i];
        nodes[node_count].min_symbol = input_symbols[i];
        nodes[node_count].left = -1;
        nodes[node_count].right = -1;
        nodes[node_count].is_leaf = 1;

        heap_push(&heap, node_count);
        node_count++;
    }

    /* Construct the Huffman tree. */
    while (heap.size > 1) {
        int left = heap_pop(&heap);
        int right = heap_pop(&heap);

        nodes[node_count].frequency =
            nodes[left].frequency + nodes[right].frequency;

        nodes[node_count].left = left;
        nodes[node_count].right = right;
        nodes[node_count].is_leaf = 0;

        nodes[node_count].min_symbol =
            nodes[left].min_symbol < nodes[right].min_symbol
            ? nodes[left].min_symbol
            : nodes[right].min_symbol;

        nodes[node_count].symbol = '\0';

        heap_push(&heap, node_count);
        node_count++;
    }

    int root = heap_pop(&heap);

    /* Get the optimal code lengths from the tree. */
    get_lengths(root, 0, codes, &code_count);

    /* Canonical order: length, then symbol. */
    qsort(codes, code_count, sizeof(Code), compare_codes);

    /* Generate canonical binary codes. */
    for (int i = 0; i < code_count; i++) {
        int length = codes[i].length;

        if (i == 0) {
            memset(codes[i].code, '0', length);
            codes[i].code[length] = '\0';
        } else {
            int previous_length = codes[i - 1].length;

            strcpy(codes[i].code, codes[i - 1].code);

            if (!increment_code(codes[i].code,
                                previous_length)) {
                printf("Error generating canonical codes.\n");
                return 1;
            }

            for (int j = previous_length; j < length; j++)
                codes[i].code[j] = '0';

            codes[i].code[length] = '\0';
        }
    }

    printf("\nCanonical Huffman Codebook:\n");
    printf("Symbol\tFrequency\tLength\tCode\n");

    long double weighted_length = 0.0L;

    for (int i = 0; i < code_count; i++) {
        long long freq = 0;

        for (int j = 0; j < n; j++) {
            if (input_symbols[j] == codes[i].symbol) {
                freq = input_freq[j];
                break;
            }
        }

        printf("%c\t%lld\t\t%d\t%s\n",
               codes[i].symbol,
               freq,
               codes[i].length,
               codes[i].code);

        weighted_length +=
            (long double)freq * codes[i].length;
    }

    printf("\nTotal frequency: %lld\n", total_frequency);
    printf("Weighted path length: %.0Lf\n", weighted_length);
    printf("Minimum expected code length: %.6Lf bits/symbol\n",
           weighted_length / total_frequency);

    return 0;
}
