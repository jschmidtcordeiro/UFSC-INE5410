#include <stdio.h>
#include <stdlib.h>

void inputArray (int ** arr, size_t *size_ptr) {
    int n;

    size_t size = *size_ptr;

    // While this does not reach the end of the line or the end of the file
    while ( scanf("%d", &n) == 1) {

        
        
        if (size == 0) {
            *arr = malloc(sizeof(int));
        } else {
            *arr = realloc(*arr, (size + 1) * sizeof(int));
        }

        (*arr)[size] = n;

        size++;

        if (getchar() == '\n') {
            break;
        }
    }

    *size_ptr = size;

    // for (size_t i = 0; i < size; i++) {
    //     printf("%d  ", arr[i]);  // Print each integer on a new line
    // }
}

void printArray (int * arr, size_t *size_ptr) {

    size_t size = *size_ptr;

    for (size_t i = 0; i < size; i++) {
        printf("%d  ", arr[i]);  // Print each integer on a new line
    }
    printf("\n");
}

int sortAscending(int * num1, int * num2) {
    return *num1 - *num2;
}

int sortDescending(int * num1, int * num2) {
    return *num2 - *num1;
}

void sort(int * arr, int size, int(* compare)(int *, int *)) {

}

int main(void) {
    size_t size = 0;
    int *arr = NULL;

    inputArray(&arr, &size);  

    printArray(arr, &size);
    
    // Sort and print sorted array in ascending order.
    printf("\n\nArray in ascending order: ");
    sort(arr, &size, sortAscending);
    printArray(arr, &size);

    // Sort and print sorted array in descending order.
    printf("\nArray in descending order: ");
    sort(arr, &size, sortDescending);
    printArray(arr, &size);


    free(arr);
}