#include <stdio.h>
main(){
    int i;
    printf("Digite um valor inteiro: ");
    scanf("%d",&i);
    while(i){
        printf("%d\n",i);
        i=i-1;
    }
}
