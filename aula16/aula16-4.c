#include <stdio.h>
void trocarValor(int *a, int *b){
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}
main(){
    int i=70,j=8;
    printf("i = %d\n",i);
    printf("j = %d\n",j);
    trocarValor(&i,&j);
    printf("i = %d\n",i);
    printf("j = %d\n",j);
}
