#include <stdio.h>
//Função
int imparPar(int num);
main(){
    int n;
    printf("Digite um numero ");
    scanf("%d",&n);
    imparPar(n)?printf("Par"):printf("Impar");

}
int imparPar(int num){
    if(num%2==0)
        return 1;
    return 0;
}
