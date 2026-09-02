#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

int quickselect(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pos = partition(arr, low, high);
        if (pos - low == k - 1)
            return arr[pos];
        if (pos - low > k - 1)
            return quickselect(arr, low, pos - 1, k);
        return quickselect(arr, pos + 1, high, k - pos + low - 1);
    }
    return -1; 
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    float median; 
    
    if (n % 2 == 1) {
  
        median = quickselect(arr, 0, n - 1, n / 2 + 1);
    } else {
   
        median = (quickselect(arr, 0, n - 1, n / 2) + quickselect(arr, 0, n - 1, n / 2 + 1)) / 2.0;
    }

    printf("Median: %.1f\n", median); 

    return 0;
}