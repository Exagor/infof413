/*
Implementation of the Quickselect algorihtm and the LazySelect algorithm
Alexandre Achten, October 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utilities.h"
#include "selection.h"

int cmp(int a, int b) {
    nbComparisons++;
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

int quickselect(int* S, int length, int k){
    /**
    * Perform a quickselect on the array S
    * @param S: the array to be sorted
    * @param k: the index of the element to be selected
    **/
    if (length < 2) return S[k];

    srand(time(NULL));

    // Generate a random pivot index between 0 and len-1
    int pivot_pos = generateRandomNumber(0, length - 1);
    int x = S[pivot_pos];

    // Create three partitions: less than, equal to, and greater than pivot
    int* less = (int*)malloc(length * sizeof(int));
    int* equal = (int*)malloc(length * sizeof(int));
    int* greater = (int*)malloc(length * sizeof(int));

    int less_len = 0, equal_len = 0, greater_len = 0;
    equal[equal_len++] = x;  // Add the pivot to the 'equal' partition

    // Distribute the elements into the three partitions
    for (int i = 0; i < length; i++) {
        if (i == pivot_pos) continue;
        int cmp_result = cmp(S[i], x);
        if (cmp_result < 0) {
            less[less_len++] = S[i];
        } else if (cmp_result > 0) {
            greater[greater_len++] = S[i];
        } else {
            equal[equal_len++] = S[i];
        }
    }

    // Recursively select from the appropriate partition
    if (k < less_len) {
        int result = quickselect(less, less_len, k);
        free(less);
        free(equal);
        free(greater);
        return result;
    }
    if (k >= less_len + equal_len) {
        int result = quickselect(greater, greater_len, k - less_len - equal_len);
        free(less);
        free(equal);
        free(greater);
        return result;
    }

    // Return the pivot if it is the kth smallest element
    free(less);
    free(equal);
    free(greater);
    return x;
}

int lazyselect(int* S, int length, int k){
    
    
    return 0;
}