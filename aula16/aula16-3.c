#include <stdio.h>
main(){
    int i=7,j=8, *p;
    p=&i;
    printf("i = %d\n",i);
    printf("j = %d\n",j);
    printf("p = %p\n",p);
    printf("*p = %d\n",*p);
    printf("&p = %p\n",&p);
    printf("&j = %p\n",&j);
}
