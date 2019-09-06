#include <stdio.h>
int dobro(int num){
    return num*2;
}
main(){
    int n,valor;
    printf("Digite um numero ");
    scanf("%d",&n);
    valor=dobro(n);
    printf("%d\n",valor+1);
}
