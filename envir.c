#include "stdio.h"
#include "unistd.h"
#include "sys/wait.h"
#include "sys/types.h"

// prog qui permet de connaitre les variables d'environnement

extern char **environ; // environ est une variable globale qui contient les variables d'environnement

int main(){

    pid_t n = fork();

    if (n == -1){
        printf("Erreur fork\n");
        return 1;
    }

    if (n == 0){
        printf("fils : %ld\n", (long) getpid());
        for (int i = 0; environ[i] != NULL; i++){
            printf("%d : %s\n", i, environ[i]);
        }        
    }

    else {
        int status;
        pid_t fils = waitpid(n, &status, 0);
        printf("père : %ld\n", (long) getpid());
        for (int i = 0; environ[i] != NULL; i++){
            printf("%d : %s\n", i, environ[i]);
        }   
    }
}