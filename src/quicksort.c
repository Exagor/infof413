/*
Implementation of the randomized quicksort in a recursive way
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utilities.h"
#include "quicksort.h"

int partition(int* S, int left, int right){
    int pivot = S[right];
    int i = left - 1;
    for (int j=left; j<right; j++){
        if (S[j]<=pivot){ // if S[j] is less than or equal to pivot
            nbComparisons++;
            i++;
            int temp = S[i]; //swap S[i] and S[j]
            S[i] = S[j];
            S[j] = temp;
        }
    }
    int temp = S[i+1]; //swap S[i+1] and S[right]
    S[i+1] = S[right];
    S[right] = temp;
    return i+1;
}


int randPartition(int* S, int left, int right){
    // pick a random index between left and right
    int randomIndex = generateRandomNumber(left, right);
    int temp = S[randomIndex]; //swap S[randomIndex] and S[right]
    S[randomIndex] = S[right];
    S[right] = temp;
    return partition(S, left, right);
}


void quicksort(int* S, int left, int right){
    /**
    * Perform a quicksort on the array S
    * @param S: the array to be sorted
    * @param left: the left index of the array
    * @param right: the right index of the array
    **/
    int mid;
    if (left < right){
        mid = randPartition(S, left, right);
        quicksort(S, left, mid - 1);
        quicksort(S, mid + 1, right);
    }

}