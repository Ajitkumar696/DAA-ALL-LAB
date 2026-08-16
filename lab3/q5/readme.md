# Special-Pattern Matrix Multiplication using Divide and Conquer — DAA Lab


## 1. Problem Statement


Given two `n × n` matrices where `n = 2^k`, each matrix has the recursive structure:


```text
M = | M1  M2 |
    | M2  M1 |

The objective is to multiply the two matrices using a Divide and Conquer approach with O(n²) time complexity.

2. Objective
Multiply two special-pattern matrices.
Use Divide and Conquer.
Exploit the repeated block structure.
Reduce unnecessary matrix multiplications.
Analyze and validate the time complexity.
3. Matrix Structure

The matrices have the form:

A = | A1  A2 |
    | A2  A1 |


B = | B1  B2 |
    | B2  B1 |

The two diagonal blocks are identical and the two off-diagonal blocks are identical.

4. Divide and Conquer Approach

Calculate:

P = (A1 + A2)(B1 + B2)


Q = (A1 - A2)(B1 - B2)

Then:

C1 = (P + Q) / 2


C2 = (P - Q) / 2

The final result is:

C = | C1  C2 |
    | C2  C1 |

This reduces the number of recursive matrix multiplications to two.

5. Algorithm
SpecialMultiply(A, B, n)


1. If n == 1:
       multiply the two elements.


2. Divide A and B into four blocks.


3. Calculate:
       A1 + A2
       A1 - A2
       B1 + B2
       B1 - B2


4. Recursively calculate:
       P = (A1 + A2)(B1 + B2)
       Q = (A1 - A2)(B1 - B2)


5. Calculate:
       C1 = (P + Q) / 2
       C2 = (P - Q) / 2


6. Construct:
       C = | C1  C2 |
           | C2  C1 |


7. Return C.
6. Recurrence

At every level, two matrix multiplications of size n/2 are performed.

The addition and subtraction of matrices require O(n²) time.

Therefore:

T(n) = 2T(n/2) + O(n²)

Using the recurrence method:

T(n) = O(n²)

Therefore, the required complexity is achieved.

7. Time Complexity
Operation	Complexity
Divide matrices	O(1)
Matrix addition/subtraction	O(n²)
Recursive multiplication	2T(n/2)
Overall	O(n²)

Thus:

Time Complexity = O(n²)
8. Example

Consider:

A = | 1 2 |
    | 2 1 |


B = | 3 4 |
    | 4 3 |

The matrices follow the required pattern:

A1 = 1, A2 = 2


B1 = 3, B2 = 4

Calculate:

P = (1 + 2)(3 + 4)
  = 3 × 7
  = 21


Q = (1 - 2)(3 - 4)
  = (-1)(-1)
  = 1

Therefore:

C1 = (21 + 1) / 2
   = 11


C2 = (21 - 1) / 2
   = 10

Result:

C = | 11 10 |
    | 10 11 |
9. Experimental Analysis

The algorithm can be tested with different matrix sizes:

n = 2, 4, 8, 16, ...

For each input size, record:

Matrix size n
Number of operations
Execution time
Result matrix

The number of operations should grow approximately proportional to n².

10. Project Structure
Q5/
├── src/
│   └── main.c
├── screenshots/
│   └── output.png
├── README.md
└── .gitignore

The main.c file contains:

Matrix input
Divide and Conquer implementation
Matrix addition and subtraction
Recursive multiplication
Result display
11. Compilation

For GCC:

gcc src/main.c -o main

Run:

./main

On Windows:

main.exe
12. Example Input
Enter n: 2


Enter matrix A:
1 2
2 1


Enter matrix B:
3 4
4 3
Output
Result:
11 10
10 11
13. Expected Results

The experiment should demonstrate that:

The special structure of the matrices is preserved.
The matrices are divided recursively.
Only two recursive multiplications are required.
Matrix addition and subtraction take O(n²) time.
The overall algorithm has O(n²) time complexity.
14. Limitations
The matrix size must be of the form 2^k.
The input matrices must follow the special pattern.
The algorithm is specifically designed for this matrix structure.
Additional handling is required for arbitrary matrices.
15. Conclusion

The special recursive structure of the matrices can be exploited to perform multiplication efficiently.

The recurrence is:

T(n) = 2T(n/2) + O(n²)

Therefore:

T(n) = O(n²)

The Divide and Conquer approach avoids unnecessary multiplications and achieves the required O(n²) time complexity.

Author

Ajit Kumar Panigrahi