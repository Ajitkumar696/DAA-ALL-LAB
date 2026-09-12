#include <stdio.h>
#include <stdlib.h>

void printShootingStrategy(int n) {
    if (n <= 1) {
        printf("Target cannot move or exist in n <= 1 spots.\n");
        return;
    }
    printf("Shooting sequence for n = %d spots: ", n);
    
    
    for (int i = 2; i <= n - 1; i++) {
        printf("%d ", i);
    }
   
    for (int i = 2; i <= n - 1; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int main(void) {
    int n = 5;
    printShootingStrategy(n);
    return 0;
}