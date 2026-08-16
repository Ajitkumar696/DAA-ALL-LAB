# Maximum and Minimum using Divide and Conquer — DAA Lab


## 1. Problem Statement


Given an array of `n` elements, find the **maximum** and **minimum** elements using the **Divide and Conquer** approach.


The number of comparisons should be bounded by:


```text
3n/2
2. Objective
Find the minimum element.
Find the maximum element.
Use Divide and Conquer.
Reduce the array into smaller subarrays.
Analyze the number of comparisons.
3. Divide and Conquer Approach

The array is divided into two halves.

             Array
               |
        ---------------
        |             |
      Left          Right
        |             |
     Min/Max        Min/Max
        \             /
         \           /
          Compare
             |
        Final Min/Max

Each half is recursively processed and the results are combined.

4. Algorithm
MinMax(array, low, high)


1. If low == high:
       min = max = array[low]


2. Find middle position.


3. Find min and max of left half.


4. Find min and max of right half.


5. Compare the two minimum values.


6. Compare the two maximum values.


7. Return final minimum and maximum.
5. Recurrence

For n elements:

T(n) = 2T(n/2) + 2

The +2 represents:

One comparison for minimum.
One comparison for maximum.

The algorithm performs approximately:

3n/2 - 2

comparisons for even n.

Therefore:

Comparisons ≤ 3n/2
6. Time Complexity
Operation	Complexity
Divide	O(1)
Find Min and Max	O(n)
Overall	O(n)

The algorithm uses approximately:

3n/2 - 2

comparisons.

7. Example

Consider:

10 4 25 2 8

The array is divided into smaller parts and the minimum and maximum of each part are found.

Final result:

Minimum = 2
Maximum = 25
8. Experimental Analysis

The program can be tested with different array sizes.

Number of Elements	Maximum Comparisons
2	1
4	4
8	10
16	22
32	46

The number of comparisons grows approximately linearly with n.

9. Project Structure
Q4/
├── src/
│   └── main.c
├── screenshots/
│   └── output.png
├── README.md
└── .gitignore
10. Compilation

For GCC:

gcc src/main.c -o main

Run:

./main

On Windows:

main.exe
11. Example
Input
Enter n: 5
10 4 25 2 8
Output
Minimum = 2
Maximum = 25
12. Expected Results

The experiment should demonstrate that:

The array is divided recursively.
Minimum and maximum are found from both halves.
The results are combined efficiently.
The number of comparisons is bounded by approximately 3n/2.
The overall time complexity is O(n).
13. Advantages
Uses the Divide and Conquer technique.
Reduces unnecessary comparisons.
Finds both minimum and maximum simultaneously.
Requires linear time.
14. Limitations
The algorithm still requires O(n) total work.
Recursive function calls use additional stack space.
The simple implementation is intended for educational comparison counting.
15. Conclusion

The Divide and Conquer approach can efficiently find both the minimum and maximum elements of an array.

The recurrence is:

T(n) = 2T(n/2) + 2

The number of comparisons is approximately:

3n/2 - 2

Therefore, the algorithm satisfies the required comparison bound and has:

O(n)

time complexity.

Author

Ajit Kumar Panigrahi