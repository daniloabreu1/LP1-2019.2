#include <stdio.h>
main(){
    int o;
    float n1, n2;
    printf("ESCOLHA AS OPCOES ABAIXO:\n");
    printf("1 - PARA SOMAR\n");
    printf("2 - PARA SUBTRAIR\n");
    printf("3 - PARA DIVIDIR\n");
    printf("4 - PARA MULTIPLICAR\n");
    printf("5 - PARA SAIR\n");
    printf("OPCAO >>>> ");
    scanf("%d",&o);
    switch(o){
        case 1:
            printf("SOMAR...\n");break;
        case 2:
            printf("SUBTRAIR...\n");break;
        case 3:
            printf("MULTIPLICAR...\n");break;
        case 4:
            printf("DIVIDIR...\n");break;
        case 5:
            printf("SAINDO...\n");break;
        default:
            printf("OPCAO INVALIDA!\n");
    }

}
