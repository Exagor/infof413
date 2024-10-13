#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "utilities.h"

int nbComparisons = 0;

int* generateRandomList(int size, int lower, int upper, int withReplacement) {
    int* list = (int*)malloc(size * sizeof(int));
    if (list == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    srand(time(NULL));
    if (withReplacement) {
        for (int i = 0; i < size; i++) {
            list[i] = generateRandomNumber(lower, upper);
        }
    } else {
        int range = upper - lower + 1;
        if (size > range) {
            fprintf(stderr, "Size is larger than the range of unique numbers available\n");
            free(list);
            return NULL;
        }

        int* temp = (int*)malloc(range * sizeof(int));
        if (temp == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            free(list);
            return NULL;
        }

        for (int i = 0; i < range; i++) {
            temp[i] = lower + i;
        }

        for (int i = 0; i < size; i++) {
            int index = rand() % (range - i);
            list[i] = temp[index];
            temp[index] = temp[range - i - 1];
        }

        free(temp);
    }

    return list;
}

int generateRandomNumber(int lower, int upper) {
    /** 
     * @param lower: the lower bound of the random number
     * @param upper: the upper bound of the random number
     * @return: a random number between lower and upper
    **/
    return (rand() % (upper - lower + 1)) + lower;
}

int verifySorted(int* list, int size) {
  /**
  * @param list: the list to be verified
  * @param size: the size of the list
  * @return: 1 if the list is sorted, 0 otherwise
  **/

    for (int i = 0; i < size-1 ; i++) {
        if (list[i] > list[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void statsToFile(char* FileName, int size, double timeTaken, int nbComparisons){
  /*Function that sends stats to a file */
  FILE *file;

  file = fopen("results/results_sort.csv", "a");
  if (file == NULL) {
    fprintf(stderr, "Error opening file\n");
    return;
  }

  const char* exactFileName = strrchr(FileName, '/');
  if (exactFileName != NULL) {
    exactFileName++; // Move past the '/'
  } else {
    exactFileName = FileName; // No '/' found, use the whole FileName
  }

  //save the file
  fprintf(file, "%s,%d,%lf,%d\n", exactFileName, size, timeTaken, nbComparisons);
  //printf("Results successfully written to file\n");
  fclose(file);
}

void statsToFile2(char* FileName, int size, int k, double timeTaken, int nbComparisons){
  /*Function that sends stats to a file */
  FILE *file;

  file = fopen("results/results_select.csv", "a");
  if (file == NULL) {
    fprintf(stderr, "Error opening file\n");
    return;
  }

  const char* exactFileName = strrchr(FileName, '/');
  if (exactFileName != NULL) {
    exactFileName++; // Move past the '/'
  } else {
    exactFileName = FileName; // No '/' found, use the whole FileName
  }

  //save the file
  fprintf(file, "%s,%d,%d,%lf,%d\n", exactFileName, size, k, timeTaken, nbComparisons);
  //printf("Results successfully written to file\n");
  fclose(file);
}