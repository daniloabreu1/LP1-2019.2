#include <stdio.h>
main(){
    int num,x;
    printf("Digite um numero para ser multiplicado ");
    scanf("%d",&num);
    for(x=0;x<=10;x++){
        printf("%2d x %2d = %2d\n",num,x,num*x);
    }
}
