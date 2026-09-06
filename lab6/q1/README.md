# DAA Lab-06

## Question 1: 1D Array Operations

Given an unsorted array of `n` integers, determine the worst-case complexity of:

1. Finding the maximum element
2. Finding the first and second largest elements
3. Finding the mean
4. Finding the median
5. Finding the standard deviation
6. Finding the mode
7. Removing all duplicates
8. Reversing the array
9. Partitioning with respect to a given pivot

### Complexity Analysis

| Operation | Worst-case Complexity |
|---|---|
| Maximum element | O(n) |
| First and second largest | O(n) |
| Mean | O(n) |
| Median | O(n log n) |
| Standard deviation | O(n) |
| Mode | O(n²) |
| Removing duplicates | O(n²) |
| Reversing | O(n) |
| Partitioning | O(n) |

### Approach

The program reads an unsorted integer array and performs each operation separately. The median is obtained after sorting a copy of the array. The mode and duplicate removal use comparisons between array elements. Partitioning places elements less than the pivot before elements greater than or equal to the pivot.

### Compile

```bash
gcc q1_array_operations.c -o q1
```

### Run

```bash
./q1
```
