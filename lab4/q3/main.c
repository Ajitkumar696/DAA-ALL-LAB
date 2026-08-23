#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == key)
            return 1;

        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

int main()
{
    int n, T;

    printf("Enter n: ");
    scanf("%d", &n);

    int S[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &S[i]);

    printf("Enter T: ");
    scanf("%d", &T);

    // Sort the array
    qsort(S, n, sizeof(int), cmp);

    // Choose two numbers
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            int required = T - S[i] - S[j];

            if (binarySearch(S, n, required))
            {
                printf("YES\n");
                printf("%d + %d + %d = %d\n",
                       S[i], S[j], required, T);
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}