#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* g(int* a) {
    return a++;
}
int f(int a) {
    return *g(&a);
}

int h() {
    int a = 23;
    f(a);
    return a;
}

int main(void) {
    printf("Resultado: %d\n", f(5));

    return 0;
}