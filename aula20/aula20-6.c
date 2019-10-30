#include <stdio.h>
#include <stdlib.h>
void imprimir(int *p,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",p[i]);
    }
    putchar('\n');
}
void salvar(int *p, int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
}
int* alocar(int t){
    return (int*)malloc(t*sizeof(int));
}

main(){
    int *p=NULL,n,i;
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&n);
    p = alocar(n);
    if(p!=NULL)
        printf("Alocou\n");
    printf("%p\n",p);
    imprimir(p,n);
    salvar(p,n);
    imprimir(p,n);
    free(p);
    imprimir(p,n);
}
