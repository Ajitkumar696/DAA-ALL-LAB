#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    FILE *file = fopen("input.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        free(arr);
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);

    file = fopen("input.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        free(arr);
        return 1;
    }

    for (int i = 0; i < n; i++)
        fscanf(file, "%d", &arr[i]);

    fclose(file);

    heapSort(arr, n);

    file = fopen("output.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        free(arr);
        return 1;
    }

    for (int i = 0; i < n; i++)
        fprintf(file, "%d ", arr[i]);

    fclose(file);

    printf("\n%d random elements generated and stored in input.txt.\n", n);
    printf("Elements sorted successfully using Heap Sort.\n");
    printf("Sorted elements stored in output.txt.\n");
    

    free(arr);

    return 0;
}