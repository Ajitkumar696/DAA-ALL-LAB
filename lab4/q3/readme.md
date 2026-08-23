# K-Sum Problem

## Problem

Given a set S of n integers and an integer T, determine whether k integers from S add up to T.

For this program, we consider k = 3.

## Approach

1. Sort the array.
2. Select two elements using two loops.
3. Calculate the required third element:

   required = T - S[i] - S[j]

4. Use Binary Search to check whether the required element exists.
5. If found, print the three numbers.

## Example

Input:

5
2 4 5 7 9
16

Output:

YES
2 + 5 + 9 = 16

## Time Complexity

For k = 3:

O(n² log n)

## Space Complexity

O(n)