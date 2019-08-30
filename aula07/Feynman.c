#include <stdio.h>
main(){
    int n,r,i;
    while(scanf("%d", &n) && n != 0){
        r=0;
        for(i=1; i<=n; i++){
            r=(i*i)+r;
        }
        printf("%d\n",r);
    }
}
