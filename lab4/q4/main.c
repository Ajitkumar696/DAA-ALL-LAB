#include <stdio.h>

typedef struct
{
    int time;
    int type;   // 1 = entry, -1 = exit
} Event;

void merge(Event a[], int l, int m, int r)
{
    Event temp[100];
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
    {
        if (a[i].time < a[j].time)
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

    printf("Enter number of people: ");
    scanf("%d", &n);

    Event events[2 * n];

    for (int i = 0; i < n; i++)
    {
        int entry, exit;

        printf("Enter entry and exit time: ");
        scanf("%d %d", &entry, &exit);

        events[2 * i].time = entry;
        events[2 * i].type = 1;

        events[2 * i + 1].time = exit;
        events[2 * i + 1].type = -1;
    }

  
    mergeSort(events, 0, 2 * n - 1);

    int people = 0;
    int maxPeople = 0;
    int start = 0;
    int end = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        int oldPeople = people;

        people += events[i].type;

        if (people > maxPeople)
        {
            maxPeople = people;
            start = events[i].time;

            if (i + 1 < 2 * n)
                end = events[i + 1].time;
        }
    }

    printf("\nMaximum people = %d\n", maxPeople);
    printf("Time = %d to %d\n", start, end);

    return 0;
}