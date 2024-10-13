#ifndef UTILITIES_H
#define UTILITIES_H

extern int nbComparisons;

int* generateRandomList(int size, int lower, int upper, int withReplacement);
int generateRandomNumber(int lower, int upper);
int verifySorted(int* list, int size);
void statsToFile(char* FileName,int size, double timeTaken, int nbComparisons);
void statsToFile2(char* FileName, int size, int k, double timeTaken, int nbComparisons);
#endif