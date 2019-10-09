#include <stdio.h>
main(){
    char l[12]="Ola Pessoal";
    puts(l);
    fgets(l,12,stdin);
    printf("%s",l);
}
