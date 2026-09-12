#include <stdio.h>

int minMovesToInvertTriangle(int n) {
    return (n * (n + 2)) / 6;
}

int main(void) {
    int rows = 4; 
    printf("Minimum moves to invert coin triangle of %d rows: %d\n", 
           rows, minMovesToInvertTriangle(rows));
    return 0;
}