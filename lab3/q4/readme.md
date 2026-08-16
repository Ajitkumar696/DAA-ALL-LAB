# Matrix Multiplication using Strassen's Method — DAA Lab


## 1. Problem Statement


Given two square matrices of size `n × n`, multiply them using **Strassen's Divide and Conquer method**.


Strassen's method reduces the number of matrix multiplications from 8 to 7 for each divide-and-conquer step.


---


## 2. Objective


- Multiply two square matrices.
- Use Divide and Conquer.
- Implement Strassen's method in C.
- Understand how Strassen reduces matrix multiplications.
- Analyze the time complexity.


---


## 3. Strassen's Method


For two `2 × 2` matrices:


```text
A = | a b |
    | c d |


B = | e f |
    | g h |

Strassen uses seven multiplications:

M1 = (a + d)(e + h)
M2 = (c + d)e
M3 = a(f - h)
M4 = d(g - e)
M5 = (a + b)h
M6 = (c - a)(e + f)
M7 = (b - d)(g + h)

The result is:

C11 = M1 + M4 - M5 + M7
C12 = M3 + M5
C21 = M2 + M4
C22 = M1 - M2 + M3 + M6
4. Divide and Conquer Approach

The matrix is divided into four smaller submatrices.

        Matrix
           |
    -------------
    |     |     |
    | A11 | A12 |
    |-----|-----|
    | A21 | A22 |
    -------------

The same process is recursively applied to the smaller matrices.

5. Algorithm
Strassen(A, B)


1. Divide A and B into four submatrices.


2. Calculate seven products M1 to M7.


3. Calculate the four result submatrices.


4. Combine the four submatrices.


5. Return the final matrix.
6. Time Complexity

The recurrence for Strassen's algorithm is:

T(n) = 7T(n/2) + O(n²)

Therefore:

T(n) = O(n^log₂7)

Since:

log₂7 ≈ 2.807

the complexity is:

O(n²·⁸⁰⁷)

Normal matrix multiplication has:

O(n³)

Therefore, Strassen's method is asymptotically faster for large matrices.

7. Example
Matrix A
1 2
3 4
Matrix B
5 6
7 8
Output
19 22
43 50
8. Experimental Analysis

The program can be tested with different matrix sizes.

Example:

Matrix Size	Method
2 × 2	Strassen
4 × 4	Strassen
8 × 8	Strassen
16 × 16	Strassen

The program can be used to verify the matrix multiplication results and study the behavior of the algorithm for increasing matrix sizes.

9. Project Structure
Q5/
├── src/
│   └── main.c
├── screenshots/
│   └── output.png
├── README.md
└── .gitignore

The main.c file contains:

Matrix input
Strassen's algorithm
Matrix multiplication
Result display
10. Compilation

For GCC:

gcc src/main.c -o main

Run:

./main

On Windows:

main.exe
11. Example
Input
Enter matrix A:
1 2
3 4


Enter matrix B:
5 6
7 8
Output
Result:
19 22
43 50
12. Expected Results

The experiment should demonstrate that:

Strassen's method correctly multiplies matrices.
The matrices are divided into smaller submatrices.
Seven multiplications are used instead of eight.
The algorithm follows the Divide and Conquer approach.
The theoretical complexity is approximately O(n²·⁸⁰⁷).
13. Advantages
Uses Divide and Conquer.
Requires fewer multiplications than the traditional method.
Faster asymptotic complexity for large matrices.
Demonstrates an important optimization technique.
14. Limitations
The basic implementation works most conveniently with matrix sizes that are powers of 2.
More additions and subtractions are required.
For small matrices, the overhead may make the normal method faster.
The implementation is more complex than standard matrix multiplication.
15. Conclusion

Strassen's method is a Divide and Conquer algorithm used for matrix multiplication.

It reduces the number of recursive multiplications from:

8 → 7

Its recurrence is:

T(n) = 7T(n/2) + O(n²)

Therefore:

T(n) = O(n²·⁸⁰⁷)

This makes Strassen's method asymptotically faster than traditional matrix multiplication, which takes O(n³) time.

Author

Ajit Kumar Panigrahi