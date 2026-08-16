Search the Defective Coin — DAA Lab

1. Problem Statement

Given n coins, all coins are expected to have exactly the same weight. However, there may be one defective coin that is lighter than the other coins.

Using a balance weighing scale, the objective is to find the defective coin if it exists, or report that no defective coin is present.

The problem must be solved using a Divide and Conquer approach in approximately:

log₂ n + c

time, where c is a positive constant.

2. Objective

Find the lighter defective coin if it exists.

Report if there is no defective coin.

Implement the solution using Divide and Conquer.

Count the number of balance comparisons.

Analyze the time complexity using the recurrence method.

Verify the logarithmic behavior of the algorithm.

3. Divide and Conquer Approach

The coins are divided into approximately two equal groups.

              n Coins
                 |
        -------------------
        |                 |
    Left Half         Right Half
        |                 |
        --------Compare---------
                 |
          Lighter Half
                 |
              Repeat

At each step:

Divide the coins into two groups.

Compare the weights of the two groups.

If the left group is lighter, search the left group.

If the right group is lighter, search the right group.

Continue until only one coin remains.

The search space is reduced by approximately half after every comparison.

4. Algorithm

DefectiveCoin(coins, low, high)

1. If low == high
       return low

2. Find the middle position.

3. Divide the coins into two halves.

4. Compare the weight of both halves.

5. If left half is lighter
       Search left half.

6. Else if right half is lighter
       Search right half.

7. Else
       No defective coin found.

8. Repeat until one coin remains.

5. Recurrence

At every step, the problem size is reduced to half.

Therefore, the recurrence relation is:

T(n) = T(n/2) + c

Expanding:

T(n) = T(n/2) + c
     = T(n/4) + 2c
     = T(n/8) + 3c
     ...
     = T(n/2^k) + kc

The process stops when:

n / 2^k = 1

Therefore:

2^k = n

Taking logarithm:

k = log₂ n

Hence:

T(n) = O(log₂ n)

6. Time Complexity

Operation

Time Complexity

Divide the coins

O(1)

Compare two groups

O(1)

Recursive search

O(log n)

Overall

O(log n)

The number of balance comparisons is approximately:

log₂ n

Therefore, the algorithm satisfies the required logarithmic time complexity.

7. Example

Consider 8 coins with the following weights:

10 10 10 10 9 10 10 10

The defective coin has weight 9.

Step 1

Divide the coins into two groups:

10 10 10 10 | 9 10 10 10

Left group weight:

40

Right group weight:

39

The right group is lighter, so the defective coin must be in the right group.

Step 2

Continue searching:

9 10 | 10 10

The lighter group is selected again.

Step 3

Continue dividing until one coin remains.

The algorithm finds:

Defective coin = Coin 5
Weight = 9

For:

n = 8

The number of levels is:

log₂(8) = 3

8. Experimental Analysis

The program can be tested with different values of n.

For each test case, record:

Number of coins n

Coin weights

Defective coin position

Number of balance comparisons

Example:

Number of Coins

Expected Comparisons

2

1

4

2

8

3

16

4

32

5

64

6

128

7

The number of comparisons increases logarithmically with the number of coins.

9. No Defective Coin

The algorithm should also handle the case where all coins have the same weight.

Input

10 10 10 10 10 10 10 10

Output

No defective coin found.

This verifies that the program can handle both possible cases:

A defective coin exists.

No defective coin exists.

10. Project Structure

Q3/
├── src/
│   └── main.c
├── screenshots/
│   └── output.png
├── README.md
└── .gitignore

The main source file contains:

Divide and Conquer implementation

Coin weight input

Defective coin search

Comparison of coin groups

Result display

The screenshots folder contains the output screenshot of the program.

11. Compilation

The program requires a C compiler such as GCC or MinGW.

For GCC:

gcc src/main.c -o main

Run the program:

./main

On Windows:

main.exe

12. Example

Input

Enter number of coins: 8

Enter weights of coins:
10 10 10 10 9 10 10 10

Output

Defective coin is at position 5

For equal-weight coins:

Input

Enter number of coins: 8

Enter weights of coins:
10 10 10 10 10 10 10 10

Output

No defective coin found.

13. Expected Results

The experiment should demonstrate that:

The coins are divided into smaller groups at every step.

Only one group needs to be searched further.

The search space is reduced by approximately half.

The number of balance comparisons grows logarithmically.

A lighter defective coin can be identified efficiently.

The algorithm can report when no defective coin is present.

For n coins, the expected number of divide-and-conquer levels is approximately:

log₂ n

14. Limitations

The simple implementation assumes that the number of coins can be divided into equal halves, such as:

2, 4, 8, 16, 32, ...

The program uses the coin weights to simulate the balance-scale comparison.

The analysis focuses on the number of balance comparisons rather than actual processor execution time.

Actual execution time can also depend on:

Compiler optimization

Processor speed

Memory/cache behavior

Operating system

Implementation details

15. Conclusion

The defective coin problem can be solved efficiently using the Divide and Conquer technique.

The recurrence relation is:

T(n) = T(n/2) + c

Therefore:

T(n) = O(log₂ n)

The search space is reduced by half at every step, allowing the possible defective coin to be found using a logarithmic number of balance comparisons.

The implementation demonstrates how Divide and Conquer can be used to efficiently solve the defective coin problem.

Author

Ajit Kumar Panigrahi