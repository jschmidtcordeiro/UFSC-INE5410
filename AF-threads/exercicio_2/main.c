#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>
// #include <sys/time.h>

// Lê o conteúdo do arquivo filename e retorna um vetor E o tamanho dele
// Se filename for da forma "gen:%d", gera um vetor aleatório com %d elementos
//
// +-------> retorno da função, ponteiro para vetor malloc()ado e preenchido
// | 
// |         tamanho do vetor (usado <-----+
// |         como 2o retorno)              |
// v                                       v
double* load_vector(const char* filename, int* out_size);


// Avalia o resultado no vetor c. Assume-se que todos os ponteiros (a, b, e c)
// tenham tamanho size.
void avaliar(double* a, double* b, double* c, int size);

typedef struct {
    double *a;
    double *b;
    double *c;
    int begin;
    int end;
} variables;

void * operation(void *param) {
    variables var = *(variables *) param;

    for (int i = var.begin; i <= var.end; i++) {
        var.c[i] = var.a[i] + var.b[i];
    }
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    // Gera um resultado diferente a cada execução do programa
    // Se **para fins de teste** quiser gerar sempre o mesmo valor
    // descomente o srand(0)
    srand(time(NULL)); //valores diferentes
    //srand(0);        //sempre mesmo valor

    //Temos argumentos suficientes?
    if(argc < 4) {
        printf("Uso: %s n_threads a_file b_file\n"
               "    n_threads    número de threads a serem usadas na computação\n"
               "    *_file       caminho de arquivo ou uma expressão com a forma gen:N,\n"
               "                 representando um vetor aleatório de tamanho N\n",
               argv[0]);
        return 1;
    }
  
    //Quantas threads?
    int n_threads = atoi(argv[1]);
    if (!n_threads) {
        printf("Número de threads deve ser > 0\n");
        return 1;
    }
    //Lê números de arquivos para vetores alocados com malloc
    int a_size = 0, b_size = 0;
    double* a = load_vector(argv[2], &a_size);
    if (!a) {
        //load_vector não conseguiu abrir o arquivo
        printf("Erro ao ler arquivo %s\n", argv[2]);
        return 1;
    }
    double* b = load_vector(argv[3], &b_size);
    if (!b) {
        printf("Erro ao ler arquivo %s\n", argv[3]);
        return 1;
    }
    
    //Garante que entradas são compatíveis
    if (a_size != b_size) {
        printf("Vetores a e b tem tamanhos diferentes! (%d != %d)\n", a_size, b_size);
        return 1;
    }
    //Cria vetor do resultado 
    double* c = malloc(a_size*sizeof(double));

    pthread_t thread_list[n_threads];
    int quociente = a_size / n_threads;
    int resto = a_size % n_threads;
    int controle = 0;

    variables var[n_threads];

    // struct timeval tv_begin;
    // struct timeval tv_end;

    // gettimeofday(&tv_begin, NULL);

    for (int i = 0; i < n_threads; i++) {

        var[i].a = a;
        var[i].b = b;
        var[i].c = c;

        var[i].end = (quociente * (i + 1)) - 1;
        var[i].end += controle;
        
        if (resto != 0) {
            controle++;
            resto--;
        }

        var[i].begin = (quociente * i);

        pthread_create(&thread_list[i], NULL, operation, (void *) &var[i]);
    }

    for (int i = 0; i < n_threads; i++) {
        pthread_join(thread_list[i], NULL);
    }
    // gettimeofday(&tv_end, NULL);
    // suseconds_t time_spent = tv_end.tv_usec - tv_begin.tv_usec;

    //    +---------------------------------+
    // ** | IMPORTANTE: avalia o resultado! | **
    //    +---------------------------------+
    avaliar(a, b, c, a_size);
    
    // printf("\n\nTime for the job: %ld\n\n", time_spent);
    
    // printf("Begin: %ld\n", begin);
    // printf("End: %ld\n", end);

    //Importante: libera memória
    free(a);
    free(b);
    free(c);

    return 0;
}
