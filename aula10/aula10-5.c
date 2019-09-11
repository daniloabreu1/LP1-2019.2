#include <stdio.h>
#define DIM 10
main(){
    int i,n,v[DIM];
    printf("DIGITE O TAMANHO DO VETOR ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("v[%d] = ",i);
        scanf("%d",&v[i]);
    }
    for(i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    putchar('\n');
}
