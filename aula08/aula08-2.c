#include <stdio.h>
imprimir(int num){
    printf("Valor %d\n",num);
}
main(){
    int n,retorno;
    printf("Digite um numero ");
    scanf("%d",&n);
    retorno=imprimir(n);
    printf("%d",retorno);
}
