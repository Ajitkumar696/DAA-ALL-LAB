#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year;
    int type; 
} Event;

typedef struct {
    int birth;
    int death;
} Scientist;

int compareEvents(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;
    if (e1->year != e2->year) {
        return e1->year - e2->year;
    }
    return e1->type - e2->type; 
}

void findPeakYear(Scientist scientists[], int n) {
    Event events[2 * n];
    for (int i = 0; i < n; i++) {
        events[2 * i].year = scientists[i].birth;
        events[2 * i].type = +1;
        events[2 * i + 1].year = scientists[i].death;
        events[2 * i + 1].type = -1;
    }

    qsort(events, 2 * n, sizeof(Event), compareEvents);

    int currentAlive = 0, maxAlive = 0, peakYear = -1;
    for (int i = 0; i < 2 * n; i++) {
        currentAlive += events[i].type;
        if (currentAlive > maxAlive) {
            maxAlive = currentAlive;
            peakYear = events[i].year;
        }
    }

    printf("Peak year: %d with %d scientists alive.\n", peakYear, maxAlive);
}

int main(void) {
    Scientist scientists[] = {
        {1879, 1955}, 
        {1843, 1910}, 
        {1867, 1934}, 
        {1856, 1943}  
    };
    int n = sizeof(scientists) / sizeof(scientists[0]);
    findPeakYear(scientists, n);
    return 0;
}