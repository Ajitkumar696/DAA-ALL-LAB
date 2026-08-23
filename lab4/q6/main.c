#include <stdio.h>

typedef struct
{
    int point;
    int type;       // 1 = start, -1 = end
} Event;

void merge(Event a[], int l, int m, int r)
{
    Event temp[100];
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
    {
        if (a[i].point < a[j].point ||
           (a[i].point == a[j].point && a[i].type > a[j].type))
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

void mergeSort(Event a[], int l, int r)
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

    Event events[2 * n];

    for (int i = 0; i < n; i++)
    {
        int l, r;

        printf("Enter interval: ");
        scanf("%d %d", &l, &r);

        events[2 * i].point = l;
        events[2 * i].type = 1;

        events[2 * i + 1].point = r;
        events[2 * i + 1].type = -1;
    }

    // Sort events
    mergeSort(events, 0, 2 * n - 1);

    int count = 0;
    int maxCount = 0;
    int answer = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        count += events[i].type;

        if (count > maxCount)
        {
            maxCount = count;
            answer = events[i].point;
        }
    }

    printf("\nPoint = %d\n", answer);
    printf("Maximum intervals = %d\n", maxCount);

    return 0;
}