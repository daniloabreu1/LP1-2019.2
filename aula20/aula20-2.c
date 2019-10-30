#include <stdio.h>
#include <stdlib.h>
main(){
    int *p=NULL,n,i;
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&n);
    p = (int*)malloc(n*sizeof(int));
    if(p!=NULL)
        printf("Alocou\n");
    printf("%p\n",p);
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    for(i=0;i<n;i++){
        printf("%d ",p[i]);
    }
}
