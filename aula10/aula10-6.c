#include <stdio.h>
void imprimir(int v[],int tam){
    int i;
    for(i=0;i<tam;i++){
        printf("%d ",v[i]);
    }
    putchar('\n');
}
void preencher(int v[],int tam){
    int i;
    for(i=0;i<tam;i++){
        printf("v[%d] = ",i);
        scanf("%d",&v[i]);
    }
}
main(){
    int v[5];
    preencher(v,5);
    imprimir(v,5);
}
