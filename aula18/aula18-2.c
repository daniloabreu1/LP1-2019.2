#include <stdio.h>

struct aluno{
    float n1, n2;
    char nome[30];
};
main(){
    struct aluno a1={10,9,"maria"};
    printf("%.1f\n",a1.n1);
    printf("%.1f\n",a1.n2);
    printf("%s\n",a1.nome);
}
