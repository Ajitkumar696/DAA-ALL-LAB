#include <stdio.h>

int main()
{
    int n, i, j, min, temp;

    printf("Enter n: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }

        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }

    printf("Sorted array:\n");

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}