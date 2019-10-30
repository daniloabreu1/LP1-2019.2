#include <stdio.h>
#include <stdlib.h>
int* alocacao(int n){
    return (int*)calloc(n,sizeof(int));
}
void salvar(int *p, int n){
    int i;
    for(i=0;i<n;i++){
        printf("Valor: ");
        scanf("%d",&p[i]);
    }
}
void imprimir(int *p, int n){
    int i;
    putchar('\n');
    if(p!=NULL){
        for(i=0;i<n;i++){
            printf("%d ",p[i]);
        }
        putchar('\n');
    }else{
        printf("NULL\n");
    }
}
int* realocar(int*p,int *n){
    int nv;
    printf("Novo tamanho: ");
    scanf("%d",&nv);
    int *aux=(int*)realloc(p,nv*sizeof(int));
    if(aux!=NULL){
        p=aux;
        *n=nv;
    }else{
        printf("nao realocou\n");
    }
    return p;
}
main(){
    int n,*p = NULL;
    scanf("%d",&n);
    p=alocacao(n);
    if(p==NULL){
        printf("nao alocou\n");
    }else{
        printf("alocou\n");
        imprimir(p,n);
        salvar(p,n);
        imprimir(p,n);
        p=realocar(p,&n);
        imprimir(p,n);
    }
}
