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
void preencher(ALUNO *a){
    printf("Digite o nome do aluno: ");
    gets(a->nome);
    printf("Digite a primeira nota: ");
    scanf("%f",&a->n1);
    printf("Digite a segunda nota: ");
    scanf("%f",&a->n2);
}
main(){
    ALUNO a1={10,9,"maria"};
    imprimir(a1);
    preencher(&a1);
    imprimir(a1);
}
