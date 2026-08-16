# Selection Sort using Loop Invariants — DAA Lab

## 1. Problem Statement

Given an array `A[1...n]`, sort the elements using the Selection Sort algorithm.

The algorithm repeatedly finds the smallest element from the unsorted part of the array and exchanges it with the first element of that part.

The correctness of the algorithm is explained using a **loop invariant**.

---

## 2. Objective

- Implement Selection Sort in C.
- Write the pseudocode for the algorithm.
- Identify the loop invariant.
- Prove correctness using initialization, maintenance, and termination.
- Analyze the worst-case and best-case running time.

---

## 3. Pseudocode

```text
SELECTION-SORT(A, n)

for i = 1 to n-1
    min = i

    for j = i+1 to n
        if A[j] < A[min]
            min = j

    exchange A[i] with A[min]
    4. Loop Invariant

The loop invariant is:

At the start of each iteration i, the subarray
A[1...i-1] contains the i-1 smallest elements
of the array in sorted order.

5. Initialization

Before the first iteration, i = 1.

The sorted portion A[1...0] is empty.

Therefore, the loop invariant is true before the first iteration.

6. Maintenance

During each iteration, the algorithm finds the smallest element from:

A[i...n]

It then exchanges this element with A[i].

Therefore, A[i] becomes the next smallest element.

The sorted portion becomes:

A[1...i]

Thus, the loop invariant remains true.

7. Termination

The loop runs until:

i = n-1

At this point, the first n-1 elements are sorted.

The last remaining element must be the largest element.

Therefore, the complete array is sorted.

8. Why Only n-1 Elements?

The algorithm only needs to process the first n-1 positions.

After placing the smallest n-1 elements in their correct positions, only one element remains.

That element must already be the largest element and therefore is automatically in the correct position.

9. Time Complexity

For each position, Selection Sort searches the remaining unsorted elements.

The number of comparisons is:

(n-1) + (n-2) + (n-3) + ... + 1

Therefore:

n(n-1)/2

comparisons are performed.

Hence:

Worst Case = Θ(n²)
10. Best-Case Running Time

Even if the array is already sorted, Selection Sort still searches the remaining elements to find the minimum.

Therefore:

Best Case = Θ(n²)
Worst Case = Θ(n²)

The best-case running time is not better than the worst-case running time.

11. C Implementation

The program implements Selection Sort using nested loops.

The outer loop selects the position where the next smallest element should be placed.

The inner loop finds the smallest element in the remaining unsorted portion.

12. Project Structure
Q6/
├── src/
│   └── main.c
├── screenshots/
│   └── output.png
├── README.md
└── .gitignore
13. Compilation

For GCC:

gcc src/main.c -o main

Run:

./main

On Windows:

main.exe
14. Example
Input
Enter n: 5


Enter elements:
64 25 12 22 11
Output
Sorted array:
11 12 22 25 64
15. Expected Results

The experiment should demonstrate that:

Selection Sort correctly sorts the array.
The smallest element is selected in each iteration.
The sorted portion grows after every iteration.
The loop invariant remains true throughout the algorithm.
The first n-1 elements are sufficient.
The best-case and worst-case running times are both Θ(n²).
Conclusion

Selection Sort maintains the following loop invariant:

At the start of iteration i, A[1...i-1] contains the i-1 smallest elements in sorted order.

The algorithm is correct because the invariant is established during initialization, preserved during maintenance, and proves the sorted array at termination.

The running time is:

Best Case  = Θ(n²)
Worst Case = Θ(n²)

Therefore, the best-case running time is not better than the worst-case running time.

Author

Ajit Kumar Panigrahi