#include <stdio.h>
void imprimir(int num){
    printf("Valor %d\n",num);
}
main(){
    int n;
    printf("Digite um numero ");
    scanf("%d",&n);
    imprimir(n);
}
