
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main(void) {
    int n;
    int ratings[MAX];
    int candies[MAX];

    long long total = 0;

    printf("Enter number of children (1-%d): ", MAX);

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of children.\n");
        return 1;
    }

    printf("Enter the ratings of the children:\n");

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &ratings[i]) != 1) {
            printf("Invalid rating.\n");
            return 1;
        }

        candies[i] = 1;
    }

    /* Left-to-right pass */
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    /* Right-to-left pass */
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] &&
            candies[i] <= candies[i + 1]) {
            candies[i] = candies[i + 1] + 1;
        }
    }

    printf("\nCandy distribution:\n");

    for (int i = 0; i < n; i++) {
        printf("Child %d (rating %d): %d candy/candies\n",
               i + 1, ratings[i], candies[i]);

        total += candies[i];
    }

    printf("\nMinimum total candies required = %lld\n", total);

    return 0;
}
