#include <stdio.h>
int dobro(int num){
    return num*2;
}
main(){
    int n;
    printf("Digite um numero ");
    scanf("%d",&n);
    printf("%d\n",dobro(n)+1);
}
