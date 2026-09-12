
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int superEggDrop(int E, int F) {
    int dp[E + 1][F + 1];

    for (int i = 0; i <= E; i++) {
        for (int j = 0; j <= F; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= E; i++) {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }
    for (int j = 1; j <= F; j++) {
        dp[1][j] = j;
    }

    for (int i = 2; i <= E; i++) {
        for (int j = 2; j <= F; j++) {
            int minDrops = INT_MAX;
            for (int k = 1; k <= j; k++) {
                int broken = dp[i - 1][k - 1];
                int survived = dp[i][j - k];
                int res = 1 + (broken > survived ? broken : survived);
                if (res < minDrops) {
                    minDrops = res;
                }
            }
            dp[i][j] = minDrops;
        }
    }
    return dp[E][F];
}

int main(void) {
    int eggs = 2, floors = 100;
    printf("Minimum drops for %d eggs and %d floors: %d\n", 
           eggs, floors, superEggDrop(eggs, floors));
    return 0;
}