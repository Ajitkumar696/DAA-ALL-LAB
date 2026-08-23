# Maximum Overlapping Intervals

## Problem

Given `n` intervals `(l, r)`, find a point that belongs to the maximum number of intervals.

An endpoint is also considered part of the interval.

## Approach

For every interval:

- Left endpoint → `+1`
- Right endpoint → `-1`

Sort all events by their point.

If two events have the same point, process the start event before the end event because endpoints are included.

Then scan the events and keep track of the number of active intervals.

## Example

Input:

```text
4
10 40
20 60
50 90
15 70