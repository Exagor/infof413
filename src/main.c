#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"
#include "utilities.h"

int SIZE = 100;
int range_low = 0;
int range_high = 1000000;

void benchmarkQuicksort(){
    printf("Benchmarking quicksort...\n");
    for (int sizes=1000; sizes<=1000000; sizes+=10000){
        SIZE=sizes;
        nbComparisons = 0;
        // generate random list
        int* list = generateRandomList(SIZE, range_low, range_high, false);
        // sort the list
        clock_t start = clock();
        quicksort(list, 0, SIZE-1);
        clock_t end = clock();
        //time elapsed
        double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        statsToFile("quicksort", SIZE, timeTaken, nbComparisons);

        //free the memory
        free(list);
    }
    printf("Benchmarking quicksort done\n");
}

int main() {
    benchmarkQuicksort();
    return 0;
}