#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>

#define DEBUG 1

void init_matrix(double* m, int rows, int columns) {
    /*
     * Mudar para estático, visto que sempre eh 
     * feita a mesma computação. Desse modo não eh
     * necessario que a cada iteracao uma thread 
     * busque o que ela deve fazer em seguida.
     */
    #pragma omp parallel for schedule(static) 
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            m[i*columns+j] = i + j;
}


void mult_matrix(double* out, double* left, double *right, 
                 int rows_left, int cols_left, int cols_right) {
    
    #ifdef DEBUG
    //Guarda ponto de início da computação
    double start = omp_get_wtime();
    #endif

    /*
     * Nesse trecho foi retirado o segundo comando
     * pragma parallel, visto que paralelizar algo que
     * já estava paralizado não eh uma boa pratica.
     * 
     * Serao criadas muitas threads e essa criacao 
     * desnecessaria eh o que o estagiario fez de errado.
     * 
     * Posteriormente foi testado a clausula reduction
     * e o seu uso resultou em um ganho de desempenho
     * consideravel
     */
    #pragma omp parallel for schedule(static) reduction(+: out[: rows_left * rows_left])
    for (int i = 0; i < rows_left; ++i) {
        for (int j = 0; j < cols_right; ++j) {
            out[i*cols_right+j] = 0;
            for (int k = 0; k < cols_left; ++k) 
                out[i*cols_right+j] += left[i*cols_left+k]*right[k*cols_right+j];
        }
    }

    #ifdef DEBUG
    double duration = omp_get_wtime()-start; //quanto tempo passou
    printf("Tempo: %f\n\n", duration);
    #endif
}

int main (int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s tam_matriz\n", argv[0]);
        return 1;
    }
    int sz = atoi(argv[1]);
    double* a = malloc(sz*sz*sizeof(double));
    double* b = malloc(sz*sz*sizeof(double));
    double* c = calloc(sz*sz, sizeof(double));

    init_matrix(a, sz, sz);
    init_matrix(b, sz, sz);

    //          c = a * b
    mult_matrix(c,  a,  b, sz, sz, sz);
    
    /* ~~~ imprime matriz ~~~ */
    char tmp[32];
    int max_len = 1;
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            int len = sprintf(tmp, "%ld", (unsigned long)c[i*sz+j]);
            max_len = max_len > len ? max_len : len;
        }
    }
    char fmt[16];
    if (snprintf(fmt, 16, "%%s%%%dld", max_len) < 0) 
        abort();
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) 
            printf(fmt, j == 0 ? "" : " ", (unsigned long)c[i*sz+j]);
        printf("\n");
    }

    free(a);
    free(b);
    free(c);

    return 0;
}
