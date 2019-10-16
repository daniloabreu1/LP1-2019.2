#include <stdio.h>
main(){
    char *p ="Ola mundo";
    puts(p);
    printf("%p\n",p);
    p="novo texto!!";
    puts(p);
    printf("%p\n",p);
}
