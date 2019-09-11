#include <stdio.h>
//Exemplo RUIM. Evite programar desta forma
main(){
    int i,n;
    printf("DIGITE O TAMANHO DO VETOR ");
    scanf("%d",&n);
    int v[n];
    for(i=0;i<n;i++){
        printf("v[%d] = ",i);
        scanf("%d",&v[i]);
    }
    for(i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    putchar('\n');
}
