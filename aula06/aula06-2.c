#include <stdio.h>
main(){
    int min, max,x, y;
    printf("Valor minimo ");
    scanf("%d",&min);
    printf("Valor maximo ");
    scanf("%d",&max);
    for(y=min;y<=max;y++){
        for(x=0; x<=10; x++){
            printf("%2d x %2d = %2d\n",y,x,y*x);
        }
        putchar('\n');
    }

}
