#include <stdio.h>
main(){
    int x=8;
    void *px;
    px = &x;
    printf("%d\n",*((int*)px));
}
