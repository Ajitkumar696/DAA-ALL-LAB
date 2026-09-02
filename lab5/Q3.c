#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int p = i + 1;

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    FILE *inputFile = fopen("input.txt", "w");

    if (inputFile == NULL)
    {
        printf("Unable to create input file.\n");
        free(arr);
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
        fprintf(inputFile, "%d ", arr[i]);
    }

    fclose(inputFile);

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL)
    {
        printf("Unable to open input file.\n");
        free(arr);
        return 1;
    }

    for (int i = 0; i < n; i++)
        fscanf(inputFile, "%d", &arr[i]);

    fclose(inputFile);

    quickSort(arr, 0, n - 1);

    FILE *outputFile = fopen("output.txt", "w");

    if (outputFile == NULL)
    {
        printf("Unable to create output file.\n");
        free(arr);
        return 1;
    }

    for (int i = 0; i < n; i++)
        fprintf(outputFile, "%d ", arr[i]);

    fclose(outputFile);

    printf("\n%d random elements generated and stored in input.txt.\n", n);
    printf("Elements sorted using Quick Sort.\n");
    printf("Sorted elements stored in output.txt.\n");

    free(arr);

    return 0;
}