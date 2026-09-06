# DAA Lab-06 - Question 2

## 2D Square Matrix Operations

For square matrices of size `n × n`, determine the worst-case complexity of:

1. Matrix Addition
2. Matrix Multiplication
3. Checking whether a matrix is a zero matrix
4. Checking whether a matrix is symmetric
5. Computing the determinant
6. In-place matrix transpose
7. Finding eigenvalues and eigenvectors

### Complexity Analysis

| Operation | Worst-case Complexity |
|---|---|
| Matrix Addition | O(n²) |
| Matrix Multiplication | O(n³) |
| Zero Matrix Check | O(n²) |
| Symmetric Matrix Check | O(n²) |
| Determinant using expansion | O(n!) |
| In-place Transpose | O(n²) |
| Eigenvalues and Eigenvectors | Not specified by the lab sheet |

The program validates the operations for square matrices. For determinant, recursive cofactor expansion is used.

### Compile

```bash
gcc q2_matrix_operations.c -o q2
```

### Run

```bash
./q2
```
