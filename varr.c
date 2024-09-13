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

    // 2
    int ret = setenv("MAVAR", "picasso", 0); // 0 pour remplacer
    if (ret == 0){
        printf("$MAVAR : %s\n", getenv("MAVAR"));
    }
    unsetenv("MAVAR");
    char *v = getenv("MAVAR");
    if (v == NULL){
        printf("$MAVAR nexiste plus.\n");
    }
    return 0;
}
