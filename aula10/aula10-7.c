#include <stdio.h>
#define L 5
#define C 3
void imprimir(float v[L][C]){
    int i,j;
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf("%.1f ",v[i][j]);
        }
        putchar('\n');
    }

}
void preencher(float v[L][C]){
    int i,j;
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf("v[%d][%d] = ",i,j);
            scanf("%f",&v[i][j]);
        }

    }
}
main(){
    float v[L][C];
    preencher(v);
    imprimir(v);
}
