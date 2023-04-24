#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//       (pai)      
//         |        
//    +----+----+
//    |         |   
// filho_1   filho_2


// ~~~ printfs  ~~~
// pai (ao criar filho): "Processo pai criou %d\n"
//    pai (ao terminar): "Processo pai finalizado!\n"
//  filhos (ao iniciar): "Processo filho %d criado\n"

// Obs:
// - pai deve esperar pelos filhos antes de terminar!


int main(int argc, char** argv) {

    // ....

    /*************************************************
     * Dicas:                                        *
     * 1. Leia as intruções antes do main().         *
     * 2. Faça os prints exatamente como solicitado. *
     * 3. Espere o término dos filhos                *
     *************************************************/

    
    int N = 2;
    // int *pid;
    int pid[N];
    int father = getpid();
    // printf("FATHER PID: %d\n\n", father);

    for (int i = 0; i < N; i++) {
        // if (N == 0) {
        //     *pid = malloc(sizeof(int));
        // } else {
        //     *pid = realloc(*pid, (N + 1) * sizeof(int));
        // }

        pid[i] = fork();
        // printf("PID: %d\n", pid[i]);
        if (pid[i] == 0) {
            printf("Processo filho %d foi criado\n", getpid());
            break;
        } 
        else {
            printf("Processo pai criou %d\n", pid[i]);
        }
    }


    while (wait(NULL) > 0) {
        // printf("Aguardando\n");
    }

    if (getpid() == father)
        printf("Processo pai finalizado!\n");

    return 0;
}
