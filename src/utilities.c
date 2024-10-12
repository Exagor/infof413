#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "utilities.h"

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

void statsToFile(char* FileName, int improvFlag, int permutFlag, int initFlag, int vndFlag, double timeTaken, int cost, int iterations){
  /*Function that sends stats to a file */
  FILE *file;

  file = fopen("raw_results/results.csv", "a");
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

  //Format the file
  const char *improvStr = (improvFlag == 0) ? "first" : "best";
  const char *permutStr;
  switch(permutFlag) {
    case 0:
      permutStr = "exchange";
      break;
    case 1:
      permutStr = "transpose";
      break;
    case 2:
      permutStr = "insert";
      break;
    default:
      permutStr = "unknown";
  }
  const char *initStr = (initFlag == 0) ? "random" : "CW";
  switch(vndFlag) {
    case 0:
      break;
    case 1:
      permutStr = "VND1";
      break;
    case 2:
      permutStr = "VND2";
      break;
    default:
      permutStr = "unknown";
  }
  //save the file
  fprintf(file,"%s,%ld,%s,%s,%s,%lf,%d,%i\n",exactFileName, improvStr, permutStr, initStr, timeTaken, cost, iterations);
  printf("Results successfully written to file\n");
  fclose(file);
}