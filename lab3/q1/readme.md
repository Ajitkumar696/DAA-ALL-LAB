# Binary vs Ternary Search — DAA Lab

## 1. Problem Statement

Given a **sorted list of `n` elements**, search for an element `x` using:

1. Binary Search
2. Ternary Search

In **Binary Search**, the list is divided into approximately two equal parts at each step, and the search continues in the half that may contain `x`.

In **Ternary Search**, the list is divided into approximately three equal parts using two middle positions, and the search continues in one of the three intervals.

The objective is to implement both algorithms in C and experimentally justify that **Binary Search is generally more efficient than Ternary Search** by comparing the number of comparisons performed.

---

## 2. Objective

* Implement Binary Search for a sorted array.
* Implement Ternary Search for a sorted array.
* Count the number of comparisons performed by both algorithms.
* Analyze the time complexity using the recurrence method.
* Compare the experimental results.
* Justify why Binary Search is generally better than Ternary Search.

---

## 3. Binary Search

Binary Search divides the search space into **two parts**.

At every step:

```text
        Sorted Array
             |
       -------------
       |           |
    Left half   Right half
```

Only one half is searched further.

### Recurrence

The recurrence relation is:

```text
T(n) = T(n/2) + c
```

Expanding:

```text
T(n) = T(n/2) + c
     = T(n/4) + 2c
     = T(n/8) + 3c
     ...
     = T(n/2^k) + kc
```

The recursion stops when:

```text
n / 2^k = 1
```

Therefore:

```text
k = log₂ n
```

Hence:

```text
T(n) = O(log n)
```

---

## 4. Ternary Search

Ternary Search divides the search space into **three parts** using two middle positions.

```text
          Sorted Array
               |
    -------------------------
    |          |            |
  Part 1     Part 2       Part 3
```

Two comparisons are generally required to determine which of the three intervals contains the element.

### Recurrence

The recurrence relation is:

```text
T(n) = T(n/3) + 2c
```

Expanding:

```text
T(n) = T(n/3) + 2c
     = T(n/9) + 4c
     = T(n/27) + 6c
     ...
     = T(n/3^k) + 2kc
```

The recursion stops when:

```text
n / 3^k = 1
```

Therefore:

```text
k = log₃ n
```

Hence:

```text
T(n) = O(log n)
```

---

## 5. Binary vs Ternary Search

| Algorithm      | Divisions per step | Approx. comparisons per step | Time Complexity |
| -------------- | -----------------: | ---------------------------: | --------------- |
| Binary Search  |                  2 |                            1 | O(log₂ n)       |
| Ternary Search |                  3 |                            2 | O(log₃ n)       |

Although both algorithms have logarithmic time complexity, Ternary Search performs more comparisons during each iteration.

The approximate comparison cost can be represented as:

```text
Binary Search  ≈ log₂(n)
Ternary Search ≈ 2 log₃(n)
```

For example, for:

```text
n = 1,000,000
```

Binary Search requires approximately:

```text
log₂(1,000,000) ≈ 20
```

levels.

Ternary Search requires approximately:

```text
log₃(1,000,000) ≈ 13
```

levels, but approximately two comparisons per level:

```text
2 × 13 ≈ 26 comparisons
```

Therefore, Binary Search can require fewer comparisons.

---

## 6. Program Structure

```text
Q2/
├── src/
│   └── main.c
└── README.md
```

The main source file contains:

* Binary Search implementation
* Ternary Search implementation
* User input
* Search result
* Comparison counting
* Comparison of both algorithms

---

## 7. Experimental Analysis

The program can be tested with different values of `n` and different search elements.

For each test case, record:

* Input size `n`
* Search element `x`
* Binary Search comparisons
* Ternary Search comparisons

Example:

| Input Size `n` | Binary Comparisons | Ternary Comparisons |
| -------------: | -----------------: | ------------------: |
|             10 |                  — |                   — |
|             50 |                  — |                   — |
|            100 |                  — |                   — |
|            500 |                  — |                   — |
|           1000 |                  — |                   — |
|           5000 |                  — |                   — |
|          10000 |                  — |                   — |

The actual values should be filled using the output of the implemented C program.

---

## 8. Justification

Binary Search is generally better than Ternary Search because it performs fewer comparisons in each iteration.

Binary Search:

```text
T(n) = T(n/2) + c
```

Ternary Search:

```text
T(n) = T(n/3) + 2c
```

Therefore, although both have:

```text
O(log n)
```

time complexity, Binary Search generally performs fewer comparison operations.

The experimental comparison count should demonstrate this behavior for suitable input sizes and search cases.

---

## 9. Important Observation

It is important to note that saying **"Binary Search is better" does not mean that Ternary Search has a worse Big-O complexity**.

Both have logarithmic complexity:

```text
Binary Search  → O(log n)
Ternary Search → O(log n)
```

The difference is in the **number of comparisons and constant factors**.

Therefore, the correct conclusion is:

> Binary Search is generally more efficient in practice for searching a sorted array because it requires fewer comparisons per iteration, even though both algorithms have logarithmic asymptotic complexity.

---

## 10. Compilation

The program requires a C compiler such as GCC or MinGW.

For GCC:

```bash
gcc main.c -o main
```

Run the program:

```bash
./main
```

On Windows:

```bash
main.exe
```

---

## 11. Example

### Input

```text
Enter number of elements: 7

Enter sorted elements:
10 20 30 40 50 60 70

Enter element to search: 50
```

### Output

```text
Binary Search: Element found at index 4
Binary comparisons: ...

Ternary Search: Element found at index 4
Ternary comparisons: ...

Binary Search is better.
```

The exact number of comparisons depends on the input array and the position of the searched element.

---

## 12. Expected Results

The experiment should demonstrate that:

* Both algorithms work correctly on a sorted array.
* Binary Search repeatedly reduces the search space to half.
* Ternary Search repeatedly reduces the search space to one-third.
* Both algorithms have `O(log n)` time complexity.
* Ternary Search performs more comparisons per iteration.
* Binary Search generally requires fewer comparisons.
* The difference becomes more meaningful as the input size increases.

---

## 13. Limitations

The experiment measures the number of comparisons rather than actual wall-clock execution time.

Actual execution time can also be affected by:

* Compiler optimization
* Processor speed
* Memory/cache behavior
* Operating system
* Implementation details

Therefore, the comparison count is used primarily to demonstrate the **algorithmic efficiency and order of growth**.

---

## 14. Conclusion

Binary Search and Ternary Search are both efficient searching algorithms for sorted arrays.

Binary Search has the recurrence:

```text
T(n) = T(n/2) + c
```

and therefore:

```text
O(log n)
```

Ternary Search has the recurrence:

```text
T(n) = T(n/3) + 2c
```

and therefore:

```text
O(log n)
```

Although Ternary Search reduces the search space to one-third at every step, it requires two comparisons per iteration. Binary Search generally requires fewer comparisons and is therefore considered more efficient for searching a sorted array.

The implementation and experimental comparison of the number of comparisons provide practical validation of this result.

## Author

**Ajit Kumar Panigrahi**