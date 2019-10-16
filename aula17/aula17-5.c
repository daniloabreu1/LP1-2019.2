#include <stdio.h>
void f(int *p, int l,int c){
    int i,j;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            //printf("%d ",p[i*c+j]);
            printf("%d ",*(p+i*c+j));
        }

    }
}

main(){
    int v[3][3]={{16, 21, 3},{45,888,90},{7,3,2}};

    f(v,3,3);
}
