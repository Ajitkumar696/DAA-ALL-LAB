
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int id;
    double value;
    double weight;
    double decay;
    double fraction;
    double taken;
    double effective_density;
} Item;

int main(void) {
    Item items[MAX];
    int n;
    double capacity;
    double remaining;
    double total_value = 0.0;
    int turn = 0;

    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid number of items.\n");
        return 1;
    }

    printf("Enter knapsack capacity: ");
    if (scanf("%lf", &capacity) != 1 || capacity <= 0) {
        printf("Invalid capacity.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter value, weight and decay rate for item %d: ",
               i + 1);

        if (scanf("%lf %lf %lf",
                  &items[i].value,
                  &items[i].weight,
                  &items[i].decay) != 3 ||
            items[i].value < 0 ||
            items[i].weight <= 0 ||
            items[i].decay <= 0) {
            printf("Invalid item data.\n");
            return 1;
        }

        items[i].id = i + 1;
        items[i].fraction = 0.0;
        items[i].taken = 0.0;
        items[i].effective_density = 0.0;
    }

    remaining = capacity;

    printf("\nSelection order and fractional choices:\n");

    while (remaining > 1e-9) {
        int best = -1;
        double best_density = 0.0;

        /* Find the remaining item with the highest
           positive density at the current turn. */
        for (int i = 0; i < n; i++) {
            if (items[i].fraction >= 1.0 - 1e-9)
                continue;

            double density =
                items[i].value / items[i].weight
                - items[i].decay * turn;

            if (density > best_density) {
                best_density = density;
                best = i;
            }
        }

        /* No item has positive effective density. */
        if (best == -1)
            break;

        double available =
            items[best].weight *
            (1.0 - items[best].fraction);

        double amount = available < remaining
                        ? available : remaining;

        double fraction = amount / items[best].weight;
        double earned = amount * best_density;

        items[best].fraction += fraction;
        items[best].taken += amount;
        items[best].effective_density = best_density;

        total_value += earned;
        remaining -= amount;

        printf("Turn %d: Item %d, density = %.2f, "
               "weight taken = %.2f, fraction = %.2f, "
               "value earned = %.2f\n",
               turn, items[best].id, best_density,
               amount, items[best].fraction, earned);

        turn++;
    }

    printf("\nFinal results:\n");

    for (int i = 0; i < n; i++) {
        printf("Item %d: weight taken = %.2f, "
               "fraction selected = %.2f\n",
               items[i].id,
               items[i].taken,
               items[i].fraction);
    }

    printf("Total weight selected: %.2f\n",
           capacity - remaining);
    printf("Total value: %.2f\n", total_value);

    return 0;
}
