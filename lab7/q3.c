#include <stdio.h>
#include <math.h>

void hanoi3(int n, char src, char dst, char aux, int *moves) {
    if (n == 0) return;
    hanoi3(n - 1, src, aux, dst, moves);
    (*moves)++;
    hanoi3(n - 1, aux, dst, src, moves);
}

void revesPuzzle(int n, char src, char dst, char aux1, char aux2, int *moves) {
    if (n == 0) return;
    if (n == 1) {
        (*moves)++;
        return;
    }
    int k = (int)(n + 1 - round(sqrt(2 * n + 1)));
    revesPuzzle(k, src, aux1, aux2, dst, moves);
    hanoi3(n - k, src, dst, aux2, moves);
    revesPuzzle(k, aux1, dst, src, aux2, moves);
}

int main(void) {
    int n = 8;
    int moves = 0;
    revesPuzzle(n, 'A', 'D', 'B', 'C', &moves);
    printf("Moves to solve Reve's Puzzle for %d disks: %d\n", n, moves);
    return 0;
}