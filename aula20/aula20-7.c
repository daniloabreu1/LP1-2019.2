#include <stdio.h>
#include <stdlib.h>


main(){
    int *p=(int*)malloc(15032385536);
    if(p!=NULL)
        printf("Alocou\n");
    else
        printf("Nao Alocou\n");
}
