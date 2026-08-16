#include <stdio.h>

int findDefective(int a[], int low, int high)
{
    if (low == high)
        return low;

    int mid = (low + high) / 2;

    int left = 0, right = 0;

    for (int i = low; i <= mid; i++)
        left += a[i];

    for (int i = mid + 1; i <= high; i++)
        right += a[i];

    if (left < right)
        return findDefective(a, low, mid);

    if (right < left)
        return findDefective(a, mid + 1, high);

    return -1;
}

int main()
{
    int n;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter weights of coins:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int result = findDefective(a, 0, n - 1);

    if (result == -1)
        printf("No defective coin found.\n");
    else
        printf("Defective coin is at position %d\n", result + 1);

    return 0;
}