#include <stdio.h>

typedef struct
{
    int start;
    int end;
} Interval;

void merge(Interval a[], int l, int m, int r)
{
    Interval temp[100];
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
    {
        if (a[i].start < a[j].start)
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];
}

void mergeSort(Interval a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

int main()
{
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval a[n];

    printf("Enter intervals:\n");

    for (int i = 0; i < n; i++)
        scanf("%d %d", &a[i].start, &a[i].end);

    // Sort intervals by starting point
    mergeSort(a, 0, n - 1);

    int count = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[count].end >= a[i].start)
        {
            // Merge
            if (a[i].end > a[count].end)
                a[count].end = a[i].end;
        }
        else
        {
            count++;
            a[count] = a[i];
        }
    }

    printf("\nMerged intervals:\n");

    for (int i = 0; i <= count; i++)
        printf("(%d, %d) ", a[i].start, a[i].end);

    return 0;
}