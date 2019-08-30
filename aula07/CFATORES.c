#include <stdio.h>
main(){
    int n, num, cont, dn, da;
    while(scanf("%d", &n) && n != 0){
        num=n;
        cont= da= 0;
        if(num>0 && num<= 1000000){
            dn=2;
            while(num!=1){
                if(num%dn==0){
                    num/=dn;
                    if(dn!=da){
                        cont++;
                        da=dn;
                    }
                }else
                    dn++;
            }
            printf("%d : %d\n",n,cont);
        }
        else
            break;
    }
}
