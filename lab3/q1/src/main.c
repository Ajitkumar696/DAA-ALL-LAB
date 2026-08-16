#include<stdio.h>
int binarySearch(int a[],int n,int x){
    int low=0;

    int high=n-1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == x)
            return mid;

        if (x < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}
int ternarySearch(int a[], int n, int x)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        if (a[mid1] == x)
            return mid1;

        if (a[mid2] == x)
            return mid2;

        if (x < a[mid1])
            high = mid1 - 1;

        else if (x > a[mid2])
            low = mid2 + 1;

        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1;
}
int main()
{
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &x);

    int b = binarySearch(a, n, x);
    int t = ternarySearch(a, n, x);

    printf("\nBinary Search: ");
    if (b != -1)
        printf("Element found at index %d\n", b);
    else
        printf("Element not found\n");

    printf("Ternary Search: ");
    if (t != -1)
        printf("Element found at index %d\n", t);
    else
        printf("Element not found\n");

    return 0;
}