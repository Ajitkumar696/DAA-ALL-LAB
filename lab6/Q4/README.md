# DAA Lab-06 - Question 4

## Sorting by Reversal

Given a permutation of integers `1` to `n`, the only allowed operation is:

`reverse(p, i, j)`

which reverses the elements from position `i` through `j`.

### O(n) Reversals

Any permutation can be sorted using at most `n - 1` prefix reversals. At each step, the largest remaining element is moved to its correct position.

Thus the number of reversals is `O(n)`.

### O(n log² n) Cost

When the cost of a reversal is its length, a divide-and-conquer strategy can be used. The permutation is divided into smaller ranges, and reversal operations are used to place elements into their appropriate portions.

The program below implements a reversal-based sorting procedure and reports the number of reversals and total reversal cost.

### Compile

```bash
gcc q4_sorting_by_reversal.c -o q4
```

### Run

```bash
./q4
```
