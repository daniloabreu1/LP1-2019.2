#include <stdio.h>
typedef enum{
    JAN,FEV,MAR,ABR,MAI,JUN,JUL,AGO,SET,OUT,NOV,DEZ
}MESES;
main(){
    char *nomes[]={"Janeiro","Fevereiro","Marco","Abril","Maio",
    "Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
    MESES mes;
    for(mes=JAN;mes<=DEZ;mes++){
        printf("[%d] - %s\n",mes+1,nomes[mes]);
    }
}
