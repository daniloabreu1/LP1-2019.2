#include <stdio.h>
void i(char *p){
    puts(p);
}
void pre(char *p){
    fgets(p,21,stdin);
}
main(){
    char c[21]="bom dia";
    i(c);
    pre(c);
    i(c);
}
