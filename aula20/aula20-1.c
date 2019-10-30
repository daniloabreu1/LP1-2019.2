#include <stdio.h>
#include <stdlib.h>
main(){
    int *p=NULL;
    p = (int*)malloc(4*sizeof(int));
    if(p!=NULL)
        printf("Alocou\n");
    printf("%p\n",p);
}
