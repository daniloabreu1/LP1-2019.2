#include <stdio.h>
#include "ponto.h"
#include "menu.c"
int main()
{
    float x,y;
    PONTO *p=NULL;

    printf("Digite os valores do ponto: ");
    scanf("%f %f",&x,&y);

    p=criar(x,y);

    if(p!=NULL){
        imprimir(p);
    }
    printf("Digite NOVOS valores do ponto: ");
    scanf("%f %f",&x,&y);
    //alterar(p,x,y);
    //imprimir(p);

    PONTO *p2=criar(x,y);

    printf("A distancia entre os dois pontos: ");
    printf("%.4f\n",distancia(p,p2));

    liberar(p);
    liberar(p2);
    return 0;
}
