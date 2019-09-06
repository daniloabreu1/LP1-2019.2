#include <stdio.h>
//Função
int x,y;
void trocaValor(){
    int aux;
    aux=x;
    x=y;
    y=aux;
}
main(){
    printf("Digite dois numero ");
    scanf("%d %d",&x,&y);
    printf("Antes da funcao\n");
    printf("X = %d\nY = %d\n",x,y);
    trocaValor(x,y);
    printf("Depois da funcao\n");
    printf("X = %d\nY = %d\n",x,y);
}

