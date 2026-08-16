#include <stdio.h>

int min, max;

void findMinMax(int a[], int low, int high)
{
    int mid;

    
    if (low == high)
    {
        min = max = a[low];
        return;
    }

    
    if (high == low + 1)
    {
        if (a[low] < a[high])
        {
            min = a[low];
            max = a[high];
        }
        else
        {
            min = a[high];
            max = a[low];
        }
        return;
    }

    mid = (low + high) / 2;


    findMinMax(a, low, mid);

    int leftMin = min;
    int leftMax = max;

    findMinMax(a, mid + 1, high);

    int rightMin = min;
    int rightMax = max;

    
    min = (leftMin < rightMin) ? leftMin : rightMin;
    max = (leftMax > rightMax) ? leftMax : rightMax;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    findMinMax(a, 0, n - 1);

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    return 0;
}