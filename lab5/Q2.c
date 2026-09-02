#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1; 
    for (int j = low; j < high; j++) {
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

    return i + 1; 
}
int kthSmallest(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int index = partition(arr, low, high);

        if (index - low == k - 1)
            return arr[index];
        if (index - low > k - 1)
            return kthSmallest(arr, low, index - 1, k);
        return kthSmallest(arr, index + 1, high, k - index + low - 1);
    }
    return -1;
}
int main() {
    int n, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int result = kthSmallest(arr, 0, n - 1, k);
    if (result != -1)
        printf("The %d'th smallest element is %d\n", k, result);
    else
        printf("Invalid input: k is out of bounds\n");

    return 0;
}