#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ponto.h"
struct ponto{
    float x,y;
};
void imprimir(PONTO *p){
    if(p!=NULL){
        printf("\nX = %.3f",p->x);
        printf("\nY = %.3f\n",p->y);
    }else{
        printf("\nPONTO NAO ALOCADO\n");
    }
}
PONTO* criar(float x,float y){
    PONTO *p = (PONTO*)malloc(sizeof(PONTO));
    if(p!=NULL){
        p->x=x;
        p->y=y;
    }
    return p;

}
void alterar(PONTO *p,int x,int y){
    if(p!=NULL){
        p->x=x;
        p->y=y;
    }
}
void liberar(PONTO *p){
    free(p);
}
float distancia(PONTO *p1, PONTO *p2){
    if(p1!=NULL && p2!=NULL){
        float x,y;
        x=pow((p2->x)-(p1->x),2);
        y=pow((p2->y)-(p1->y),2);
        return sqrt(x+y);
    }
    return 0;
}
