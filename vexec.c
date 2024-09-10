// Il faut créer un prog qui appelle exxe.c avec execv().
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "errno.h"

int main(){

    pid_t n = fork();

    if (n == -1 ){
        printf("Erreur dans le fork.\n");
    }

    if (n == 0 ){
    char *argv[] = {"./exxe", (char*) NULL}; // on peut ajouter des arguments
    printf("pid avant exec() : %ld\n", (long) getpid()); // on voit que c'est le mm pid.
    execv("./exxe", argv);
    printf("error : %d\n", errno);
    // cette ligne ne sera pas lue
    }

    else {
        int status;
        pid_t fils = waitpid(n, &status, 0);
        printf("fin du père.\n");
    }
    return 0;
}