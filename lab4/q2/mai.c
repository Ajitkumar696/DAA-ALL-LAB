#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int binarySearch(int a[], int n, int key)
{
    int l = 0, h = n - 1;

    while (l <= h)
    {
        int m = (l + h) / 2;

        if (a[m] == key)
            return 1;
        else if (a[m] < key)
            l = m + 1;
        else
            h = m - 1;
    }

    return 0;
}

int main()
{
    int n, x;

    printf("Enter n: ");
    scanf("%d", &n);

    int s1[n], s2[n];

    printf("Enter S1: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &s1[i]);

    printf("Enter S2: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &s2[i]);

    printf("Enter x: ");
    scanf("%d", &x);

    qsort(s2, n, sizeof(int), cmp);

    for (int i = 0; i < n; i++)
    {
        if (binarySearch(s2, n, x - s1[i]))
        {
            printf("Pair found: %d + %d = %d\n",
                   s1[i], x - s1[i], x);
            return 0;
        }
    }

    printf("No pair found\n");

    return 0;
}