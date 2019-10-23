#include <stdio.h>
typedef struct{
    char rua[45],num[10],bairro[25],cidade[45];
}ENDER;

typedef struct{
    float n1, n2;
    char nome[30];
    ENDER e;
}ALUNO;

void imprimir(ALUNO a){
    printf("\n\n------------------------\n");
    printf("%.1f\n",a.n1);
    printf("%.1f\n",a.n2);
    printf("%s\n",a.nome);
    printf("%s, %s - %s, %s\n",a.e.rua,a.e.num,a.e.bairro,a.e.cidade);
    printf("\n------------------------\n");
}
void preencher(ALUNO *a){
    setbuf(stdin, NULL);
    printf("\n\n------------------------\n");
    printf("Digite o nome do aluno: ");
    gets(a->nome);
    printf("Digite a primeira nota: ");
    scanf("%f",&a->n1);
    printf("Digite a segunda nota: ");
    scanf("%f",&a->n2);
    setbuf(stdin,NULL);
    printf("Digite a rua: ");
    gets(a->e.rua);
    printf("Digite a numero: ");
    gets(a->e.num);
    printf("Digite a bairro: ");
    gets(a->e.bairro);
    printf("Digite a cidade: ");
    gets(a->e.cidade);
    printf("\n------------------------\n");
}
main(){
    ALUNO alunos[10];
    int i;
    for(i=0;i<2;i++){
        preencher(&alunos[i]);
    }

    for(i=0;i<2;i++){
        imprimir(alunos[i]);
    }
}
