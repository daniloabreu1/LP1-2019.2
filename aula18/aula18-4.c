#include <stdio.h>
typedef struct{
    float n1, n2;
    char nome[30];
}ALUNO;
void imprimir(ALUNO a){
    printf("%.1f\n",a.n1);
    printf("%.1f\n",a.n2);
    printf("%s\n",a.nome);
}
main(){
    ALUNO a1={10,9,"maria"};
    imprimir(a1);
}
