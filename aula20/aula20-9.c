#include <stdio.h>
#include <stdlib.h>
void imprimir(int **p,int lin,int col){
    int i,j;
    putchar('\n');
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            printf("%d ",p[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}
void salvar(int **p, int lin,int col){
    int i,j;
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            scanf("%d",&p[i][j]);
        }
    }
}
int** alocar(int lin,int col){
    int i,**m;
    m=(int**)malloc(lin*sizeof(int*));
    for(i=0;i<lin;i++){
        m[i]=(int*)calloc(col,sizeof(int));
    }
    return m;
}
void liberar(int **m,int lin){
    int i;
    for(i=0;i<lin;i++)
        free(m[i]);
    free(m);
    printf("Matriz Liberada da Memoria\n");
}
main(){
    int **mat=NULL,lin,col;
    printf("Digite as Linhas da matriz: ");
    scanf("%d",&lin);
    printf("Digite as Colunas da matriz: ");
    scanf("%d",&col);
    mat = alocar(lin,col);
    imprimir(mat,lin,col);
    salvar(mat,lin,col);
    imprimir(mat,lin,col);
    liberar(mat,lin);
}
