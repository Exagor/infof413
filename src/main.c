/*
Alexandre Achten, October 2024
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"
#include "selection.h"
#include "utilities.h"

int SIZE = 100000;
int range_low = 0;
int range_high = 1000000; // previously 1000000

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

void benchmarkQuickselect(){
    printf("Benchmarking quickselect...\n");
    nbComparisons = 0;
    int* list = generateRandomList(SIZE, range_low, range_high, false);
    int k = SIZE/2; 
    clock_t start = clock();
    int kth = quickselect(list,SIZE, k);
    clock_t end = clock();
    printf("The %dth number is : %d\n",k, kth);

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    statsToFile2("quickselect", SIZE, k, timeTaken, nbComparisons);

    printf("\n");
    printf("Benchmarking quickselect done\n");
}

void benchmarkLazyselect(){
    printf("Benchmarking lazyselect...\n");
    nbComparisons = 0;
    int* list = generateRandomList(SIZE, range_low, range_high, false);
    int kth = lazyselect(list,SIZE, SIZE/2);
    for (int i = 0; i < SIZE; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    printf("The %dth number is : %d\n",SIZE/2, kth);
    printf("Benchmarking lazyselect done\n");
}

int main() {
    // benchmarkQuicksort();
    benchmarkQuickselect();
    return 0;
}