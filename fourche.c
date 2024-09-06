#include <unistd.h>
#include <stdio.h>
#include <sys/types.h> // pid_t
#include <sys/wait.h> // waitpid

int main(){
    int nb = 7;
    pid_t f1 = fork();

    if (f1 == -1){
        printf("error dans le fork.\n");
        return 1;
    }

    if (f1 == 0){
        printf("fils PID : %ld, PPID : %ld\n", (long) getpid(), (long) getppid());
        nb = 3;
        printf("nb = %d\n", nb);
        sleep(15);
    }

    else {
        printf("père PID : %ld, PPID : %ld, FPID : %ld\n", (long) getpid(), (long) getppid(), (long) f1);
        int status;
        pid_t fils = wait(&status);
        printf("fils %ld terminé", (long) fils);
        printf("nb = %d\n", nb); // les variables ne sont pas partagées
    }
    return 0;
}