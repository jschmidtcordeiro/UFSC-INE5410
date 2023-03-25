#include <stdio.h>
#include <stdlib.h>

typedef struct MinMax {
    int min;
    int max;
}MinMax;

MinMax *getMinMax(int * array, const int SIZE);

int main(void) {
    int SIZE = 4;
    int array[] = {34, 8, 98, 73};

    MinMax *arr = getMinMax(array, SIZE);

    for (int i = 0; i < SIZE; i++) {
        printf("%d", array[i]);
    }

    printf("\nMin: %d\n", arr->min);
    printf("Max: %d\n", arr->max);


    free(arr);
}

MinMax *getMinMax(int *array, const int SIZE) {

    MinMax *stc = (MinMax *) malloc(sizeof(MinMax));

    printf("%d\n", stc->max);
    for (int i = 0; i < SIZE; i++) {
        if (array[i] > stc->max) {
            stc->max = array[i];
        } 
        else if(array[i] < stc->min) {
            stc->min = array[i];
        }
    }

    return stc;
}