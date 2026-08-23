# Pair Sum from Two Sets

## Problem

Given two sets `S1` and `S2`, each containing `n` elements, and a number `x`.

We need to determine whether there exists:

- One element from `S1`
- One element from `S2`

such that:

a + b = x

## Approach

We use the following approach:

1. Store `S1` and `S2` in arrays.
2. Sort `S2` using `qsort()`.
3. For every element `a` in `S1`, calculate:

   `required = x - a`

4. Use Binary Search to check whether `required` exists in `S2`.
5. If found, a valid pair exists.
6. If no pair is found, print "No pair found".

## Example

### Input

```text
Enter size of sets: 5

Enter elements of S1:
2 5 8 12 15

Enter elements of S2:
1 4 7 10 20

Enter x: 19