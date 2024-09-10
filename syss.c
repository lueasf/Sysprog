#include "stdio.h"
#include "stdlib.h"

int main(){
    int ret = system("ps -ef");
    printf("retour de la commande : %d\n", ret);
}