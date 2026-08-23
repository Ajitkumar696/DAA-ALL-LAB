# Maximum People at Party

## Problem

Given the entry and exit time of `n` people at a party, find the time when the maximum number of people were present at the same time.

All entry and exit times are distinct.

## Approach

For every person, create two events:

- Entry → `+1`
- Exit → `-1`

Sort all events according to time.

Then scan the events:

- Add `1` when a person enters.
- Subtract `1` when a person exits.
- Keep track of the maximum number of people.

## Example

### Input

```text
4
2 8
4 7
5 10
9 12