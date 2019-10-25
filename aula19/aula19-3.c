#include <stdio.h>
enum dias{DOM=1,SEG,TER,QUA,QUI,SEX,SAB};
main(){
    enum dias d;
    d=TER;
    printf("%d\n",TER);
    d=TER+DOM;
    printf("%d\n",d);
}
