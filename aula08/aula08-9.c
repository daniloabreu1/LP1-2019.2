#include <stdio.h>
//Fun��o
int contador(){
    static int v=0;
    return ++v;
}
main(){
    printf("Primeira Chamada\n");
    printf("%d\n",contador());
    printf("Segunda Chamada\n");
    printf("%d\n",contador());

}

