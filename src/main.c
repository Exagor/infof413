#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "quicksort.h"
#include "utilities.h"

int SIZE = 100;
int range_low = 0;
int range_high = 100;

int main() {
    // generate random list
    int* list = generateRandomList(SIZE, range_low, range_high, false);
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", list[i]);
    }

    // sort the list
    quicksort(list, 0, SIZE-1);

    // print the sorted list
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    //free the memory
    free(list);
}