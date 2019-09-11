#include <stdio.h>

main(){
    int v1[5]={10,8,6,4,2};
    printf("%d\n",v1[0]);
    printf("%d\n",v1[4]);
    v1[1]=897;
    printf("%d\n",v1[1]);
    printf("%d\n",v1[0]*v1[1]);

}
