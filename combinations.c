#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "combinations.h"

int startForCombination() {
    int number;
    int k;
    int *array;
    int numberOfSolutions = 0;

    printf("Select 2 numbers n and k shown: ");
    scanf("%d %d", &number, &k);

    array = calloc(k + 1, sizeof(int));

    combine(number, k, array, 0, 1, &numberOfSolutions);

    free(array);

    printf("total of: %d solutions", numberOfSolutions);

    return 0;
}

void printArrayCombination(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

void combine(int number, int k, int *array, int position, int start, int *solutions) {
    if (position == k) {
        printArrayCombination(array, k);
        (*solutions)++;
        printf("\n");
        return;
    }

    for (int i = start; i <= number; i++) {
        array[position] = i;
        combine(number, k, array, position + 1, i + 1, solutions);
    }
}

