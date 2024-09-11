#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

int main(){
    char* val = getenv("COOLVAR");
    if (val != NULL){
        printf("$COOLVAR : %s\n", val);
    }
    else {
        setenv("COOLVAR", "cool value", 1);
        printf("La variable $COOLVAR n'existe pas\n");
    }
}