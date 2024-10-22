/*
Implementation of the Quickselect algorihtm and the LazySelect algorithm
Alexandre Achten, October 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "utilities.h"
#include "selection.h"
#include "quicksort.h"

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
    * @param length: the length of the array
    * @param k: the index of the element to be selected
    **/
    if (length < 2) return S[k];

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

int cmpfunc(const void *a, const void *b) {
    nbComparisons++;
    return (*(int *)a - *(int *)b);
}

int lazyselect(int* S, int length, int k){
    /**
    * Perform a lazyselect on the array S
    * @param S: the array to be selected
    * @param length: the length of the array
    * @param k: the index of the element to be selected
    **/
    while (1){
        //Pick n^(3/4) elements uniformly at random with replacement
        int R_size = (int)pow(length, 0.75);
        int *R = (int *)malloc(R_size * sizeof(int));

        for (int i = 0; i < R_size; i++) {
            R[i] = S[rand() % length];
        }

        // Sort R with quicksort
        qsort(R, R_size, sizeof(int), cmpfunc);

        //Compute l and h
        double x = k * pow(length, -0.25);
        int l = fmax((int)(x - sqrt(length)), 1);
        int h = fmin((int)(x + sqrt(length)), R_size);
        int a = R[l - 1];
        int b = R[h - 1];
        free(R);

        // Determine the rank of a and b in S
        int rs_a = 0, rs_b = 0;
        int *P = (int *)malloc(length * sizeof(int));
        int P_size = 0;
        for (int i = 0; i < length; i++) {
            if (S[i] < a) rs_a++;
            if (S[i] <= b) rs_b++;
            if ((k < pow(length, 0.25) && S[i] >= b) || (k > length - pow(length, 0.25) && S[i] <= a) || 
                (k >= pow(length, 0.25) && k <= length - pow(length, 0.25) && S[i] >= a && S[i] <= b)) {
                P[P_size++] = S[i];
            }
        }
        // Check the size of P
        if (P_size <= 4 * pow(length, 0.75) + 2) {
            // Sort P and return the kth smallest element
            qsort(P, P_size, sizeof(int), cmpfunc);
            int result = P[k - rs_a];
            free(P);
            return result;
        }
        // Free memory and repeat if the conditions are not met
        free(P);
    }
}