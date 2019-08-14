#include <stdio.h>
main(){
    char o;
    float n1, n2;
    printf("ESCOLHA AS OPCOES ABAIXO:\n");
    printf("S - PARA SOMAR\n");
    printf("U - PARA SUBTRAIR\n");
    printf("V - PARA DIVIDIR\n");
    printf("M - PARA MULTIPLICAR\n");
    printf("X - PARA SAIR\n");
    printf("OPCAO >>>> ");
    scanf("%c",&o);
    switch(o){
        case 's':
        case 'S':
            printf("SOMAR...\n");break;
        case 'u':
        case 'U':
            printf("SUBTRAIR...\n");break;
        case 'v':
        case 'V':
            printf("DIVIDIR...\n");break;
        case 'm':
        case 'M':
            printf("MULTIPLICAR...\n");break;
        case 'x':
        case 'X':
            printf("SAINDO...\n");break;
        default:
            printf("OPCAO INVALIDA!\n");
    }

}
