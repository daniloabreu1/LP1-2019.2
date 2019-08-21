#include <stdio.h>
main(){
    int i, f;
    printf("Digite um valor inicial: ");
    scanf("%d",&i);
    printf("Digite um valor final: ");
    scanf("%d",&f);
    while(i<=f){
        printf("%d\n",i);
        i=i+1;
    }
}
