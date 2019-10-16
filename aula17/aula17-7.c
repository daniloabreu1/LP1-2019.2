#include <stdio.h>
void i(char *p){
    puts(p);
}
void pre(char *p){
    fgets(p,21,stdin);
    p[2]='X';
}
main(){
    char c[21]="bom dia";
    i(c);
    pre(c);
    i(c);
}
