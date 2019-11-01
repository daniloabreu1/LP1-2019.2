#ifndef PONTO_HEADER
#define PONTO_HEADER

typedef struct ponto PONTO;
void imprimir(PONTO *p);
PONTO* criar(float x,float y);
void alterar(PONTO *p,int x,int y);
void liberar(PONTO *p);
float distancia(PONTO *p1,PONTO *p2);
#endif // PONTO_HEADER
