#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int f(int a) {
    if (a % 2 != 0 && a < 20) {
        return a;
    } else if (&a) {
        if (a < 0) return 2*a;
    } else {
        return 27;
    }
    return 31;
}

int main(void) {
    printf("Se a for 2, a função retorna %d\n", f(2));
    printf("Se a for -3, a função retorna %d\n", f(-3));
    printf("Se a for -2, a função retorna %d\n", f(-2));
    printf("Se a for 0, a função retorna %d\n", f(0));

    return 0;
}