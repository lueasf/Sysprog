#include <unistd.h>
#include <stdio.h>

int main(){
    // si ce sont des int, on trsfrm en long, peut-etre pid_t
    printf("PID : %ld, PPID : %ld\n", (long) getpid(), (long) getppid());
    sleep(5);
    printf("PID?\n");
    return 0;
}