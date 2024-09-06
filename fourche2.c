#include <unistd.h>
#include <stdio.h>
#include <sys/types.h> // pid_t
#include <sys/wait.h> // waitpid

int main(){
    int nb = 7;
    pid_t f1 = fork();
    pid_t f2 = fork();

    if (f1 == -1 || f2 == -1){
        printf("error dans le fork.\n");
        return 1;
    }

    if (f1 != 0 && f2 != 0){
        printf("père PID : %ld, PPID : %ld\n", (long) getpid(), (long) getppid());
        pid_t fils;
        int status;
        while (fils = wait(&status) > 0){ // car res de wait est le pid du fils
            printf("fils %ld terminé.\n", (long) fils);
        }
    }

    else if (f1 == 0 && f2 != 0){
        printf("fils1 PID : %ld, PPID : %ld, FPID : %ld\n", (long) getpid(), (long) getppid(), (long) f1);
        sleep(3);
    }
    else if (f1 != 0 && f2 == 0){
        printf("fils2 PID : %ld, PPID : %ld, FPID : %ld\n", (long) getpid(), (long) getppid(), (long) f2);
        sleep(3);
    }
    else {
        printf("fils du fils1 PID : %ld, PPID : %ld, FPID : %ld\n", (long) getpid(), (long) getppid(), (long) f1);
    }
    return 0;
}