# Merge Overlapping Intervals

## Problem

Given a list of `n` intervals `(x, y)`, merge all overlapping intervals.

Example:

Input:

(1,3), (2,6), (8,10), (7,18)

Output:

(1,6), (7,18)

## Approach

1. Sort the intervals by their starting point.
2. Compare each interval with the current interval.
3. If they overlap, merge them.
4. If they do not overlap, store the current interval and start a new one.

Two intervals overlap when:

current_end >= next_start

## Example

Input:

```text
4
1 3
2 6
8 10
7 18