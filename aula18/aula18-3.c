#include <stdio.h>

struct aluno{
    float n1, n2;
    char nome[30];
};
void imprimir(struct aluno a){
    printf("%.1f\n",a.n1);
    printf("%.1f\n",a.n2);
    printf("%s\n",a.nome);
}
main(){
    struct aluno a1={10,9,"maria"};
    imprimir(a1);
}
