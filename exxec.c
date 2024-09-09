#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    printf("Programme de exec !!\n");
    printf("pid après exec() : %ld\n", (long) getpid());
    printf("il y a %d paramètres : \n", argc);
    for (int i = 0; i < argc; i++){
        printf("paramètre %d : %s\n", i, argv[i]);
    }
}