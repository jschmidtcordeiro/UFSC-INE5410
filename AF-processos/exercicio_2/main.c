#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


//                          (principal)
//                               |
//              +----------------+--------------+
//              |                               |
//           filho_1                         filho_2
//              |                               |
//    +---------+-----------+          +--------+--------+
//    |         |           |          |        |        |
// neto_1_1  neto_1_2  neto_1_3     neto_2_1 neto_2_2 neto_2_3

// ~~~ printfs  ~~~
//      principal (ao finalizar): "Processo principal %d finalizado\n"
// filhos e netos (ao finalizar): "Processo %d finalizado\n"
//    filhos e netos (ao inciar): "Processo %d, filho de %d\n"

// Obs:
// - netos devem esperar 5 segundos antes de imprmir a mensagem de finalizado (e terminar)
// - pais devem esperar pelos seu descendentes diretos antes de terminar

int main(int argc, char** argv) {

    // ....

    /*************************************************
     * Dicas:                                        *
     * 1. Leia as intruções antes do main().         *
     * 2. Faça os prints exatamente como solicitado. *
     * 3. Espere o término dos filhos                *
     *************************************************/


    int N = 2;
    // pid_t *pid;
    pid_t pid[N];
    pid_t father = getpid();

    // Cria dois processos filhos
    for (int i = 0; i < N; i++) {

        pid[i] = fork();
        if (pid[i] == 0) {
            printf("Processo %d, filho de %d\n", getpid(), getppid());
            fflush(stdout);
            // Cada processo filho deve criar mais 3 processos
            // 3 Netos para cada filho
            // 6 Netos
            for (int i = 0; i < 3; i++) {
                pid_t x = fork();
                // Neto printa processo
                if (x == 0) {
                    printf("Processo %d, filho de %d\n", getpid(), getppid());
                    fflush(stdout);
                    sleep(5);
                    break;
                }
            }
            break;
        }
    }


    while (wait(NULL) > 0) {
        // printf("Aguardando\n");
    }

    if (getpid() == father) {
        printf("Processo principal %d finalizado\n", father);
        fflush(stdout);
    }
    else {
        printf("Processo %d finalizado\n", getpid());
        fflush(stdout);
    }
    

    return 0;
}
