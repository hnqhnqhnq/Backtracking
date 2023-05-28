#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "permutation.h"

int startForPermutation() {
    int number;
    int *array;
    bool *explored;

    printf("Select a number to have its permutations shown: ");
    scanf("%d", &number);

    array = calloc(number+1, sizeof(int));
    explored = malloc((number + 1) * sizeof(bool));

    for (int i = 1; i <= number; i++)
        explored[i] = false;

    permute(number,array,0,explored);

    free(array);
    free(explored);

    return 0;
}

void printArrayPermutation(int *array, int size){
    for(int i=0;i<size;i++)
        printf("%d ", array[i]);
}

void permute(int number, int *array, int position, bool *explored){
    if(position==number){
        printArrayPermutation(array,number);
        printf("\n");
        return;
    }

    for(int i=1; i<=number;i++){
        if(!explored[i]){
            array[position]=i;
            explored[i]=true;
            permute(number,array,position+1,explored);
            explored[i]=false;
        }
    }
}
