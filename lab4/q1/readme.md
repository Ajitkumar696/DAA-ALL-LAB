# Sort Items by Color

## Problem

Given `n` pairs of items where each pair contains:

- A number
- A color: Red, Blue, or Yellow

The numbers are already sorted.

The task is to sort the items by color in the order:

**Red → Blue → Yellow**

The numbers belonging to the same color must remain sorted.

## Approach

We use three separate arrays:

- `red[]`
- `blue[]`
- `yellow[]`

We scan the input only once.

For every item:

- If the color is Red, put the number in `red[]`
- If the color is Blue, put the number in `blue[]`
- If the color is Yellow, put the number in `yellow[]`

Finally, print the three arrays in the order:

**Red → Blue → Yellow**

Since the input numbers are already sorted, the numbers inside each color remain sorted automatically.

## Time Complexity

The input is scanned once.

**Time Complexity: O(n)**

## Space Complexity

We use three arrays to store the items.

**Space Complexity: O(n)**

## Color Representation

```text
1 = Red
2 = Blue
3 = Yellow