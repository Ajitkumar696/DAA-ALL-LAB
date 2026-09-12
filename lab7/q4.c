#include <stdio.h>

void turnOff(int n);
void turnOn(int n);

void turnOff(int n) {
    if (n <= 0) return;
    if (n == 1) {
        printf("Toggle switch 1\n");
        return;
    }
    turnOff(n - 2);
    printf("Toggle switch %d\n", n);
    turnOn(n - 2);
    turnOff(n - 1);
}

void turnOn(int n) {
    if (n <= 0) return;
    if (n == 1) {
        printf("Toggle switch 1\n");
        return;
    }
    turnOn(n - 1);
    turnOff(n - 2);
    printf("Toggle switch %d\n", n);
    turnOn(n - 2);
}

int main(void) {
    int n = 4;
    printf("Steps to turn off %d switches:\n", n);
    turnOff(n);
    return 0;
}