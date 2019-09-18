#include <stdio.h>
void imprimirMatriz(int m[3][2]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            printf("%d ",m[i][j]);
        }
        putchar('\n');
    }
}
void preencherMatriz(int m[3][2]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            scanf("%d",&m[i][j]);
        }
    }
    putchar('\n');
}
main(){
    int m[3][2];
    preencherMatriz(m);
    imprimirMatriz(m);
}
