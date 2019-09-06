#include <stdio.h>
//Função
int dobro(int num){
    return num*2;
}
//Procedimento
void linha(void){
    int n;
    for(n=0;n<10;n++)
        printf("_");
    putchar('\n');
}
main(){
    int n;
    printf("Digite um numero ");
    scanf("%d",&n);
    linha();
    printf("%d\n",dobro(n)+1);
    linha();
}
