#include <stdio.h>
#include <stdlib.h>
/*
ESTE PROGRAMA IMPLEMENTA A ESTRUTURA DE DADOS LISTA.

TANTO A INSER��O QUANTO A REMO�AO PODERAO SER EM QUALQUER PARTE DA LISTA

NO PROGRAMA ABAIXO SAO IMPLEMENTADAS AS TAREFAS DE:

--> CRIAR UMA LISTA
--> INSERIR ELEMENTOS EM UMA LISTA DE FORMA ORDENADA
--> REMOVER ELEMENTOS EM UMA LISTA
--> VERIFICAR SE A LISTA EST� VAZIA
--> VERIFICAR A QUANTIDADE DE ELEMENTOS DA LISTA
--> IMPRIMIR A LISTA
--> LIBERAR O ESPA�O DE MEM�RIA ALOCADA PARA LISTA E SEUS ELEMENTOS

*/

//ESTRUTURA QUE ARMAZENARA OS DADOS DO ALUNO
typedef struct {
    char nome[31];
    int codigo;
    float n1, n2;
}ALUNO;

//ESTRUTURA QUE RECEBER� O CONJUNTO DE DADOS DO ALUNO E O ENDERE�O DO PROXIMO ELEMENTO DA LISTA (O ALUNO A SEGUIR)
typedef struct elemento{
    ALUNO dados;//AQUI, SER� ARMAZENADOS OS DADOS DO ALUNO
    struct elemento *prox;//ESTE CAMPO SER� UM PONTEIRO PARA O PR�XIMO ELEMENTO DA LISTA (QUE TAMB�M SER� DO "TIPO" STRUCT ELEMENTO)
} ELEM;

//A ESTRUTURA ABAIXO TERA O APONTADOR DO PRIMEIRO ELEMENTO DA LISTA
typedef struct{
    ELEM *inicio; //ESTRUTURA QUE RECEBER� O PRIMEIRO ELEMENTO (DADOS DO ALUNO E PROXIMO ELEMENTO) DA LISTA
}LISTA;

//FUN��O QUE RETORNA O ENDERE�O DE MEM�RIA DE UMA LISTA VAZIA.
LISTA* criar(){
    LISTA* li = (LISTA*) malloc(sizeof(LISTA)); //ALOCA O ESPA�O NA MEM�RIA
    if(li != NULL) //SE O SISTEMA OPERACIONAL ALOCAR, ENTRA NO IF.
    {
        li->inicio= NULL; //INICIA A POSI��O INICIAL COM NULL
    }
    return li;//RETORNA O ENDERE�O DA LISTA
}

//FUN��O QUE DESALOCA O ESPA�O NA MEM�RIA DO S.O.
void liberar(LISTA *li){
    if(li !=NULL){
        ELEM * aux;//CRIA UM PONTEIRO DE UMA ESTRUTURA ELEMENTO, PARA SERVIR DE AUXILIAR PARA O PROCESSO DE LIBERA��O
        while(li->inicio!=NULL) //VERIFICA SE A POSI��O INICIA TEM ALGUMA ESTRUTURA. CASO TENHA, ENTRA NO IF
        {
            aux = li->inicio;//O PONTEIRO AUXLIAR RECEBE O ENDERE�O DO PRIMEIRO ELEMENTO DA MINHA LISTA.
            li->inicio = li->inicio->prox;//A POSI��O DE INICIO DA MINHA LISTA PASSA A APONTAR AO VALOR QUE ESTAVA NO CAMPO PROX�MO (APONTAR� AO SEGUNO ELEMENTO)
            free(aux);//COM A POSI��O INICIAL APONTANDO PARA SEGUNDA POSI��O, A PRIMEIRA (QUE ESTAVA GUARDADA NO ELEMENTO AUXILIAR) SER� LIBERADA.
        }//SE A POSI��O DE INICIO APONTAR PARA NULL, SIGINIFICA QUE NAO H� MAIS ELEMENTOS NA MINHA LISTA.
        free(li);//O ESPA�O DE MEM�RIA ALOCADO PARA MINHA LISTA � LIBERADO.
    }
}

//FUN��O ABAIXO RETORNA UM INTEIRO COM A QUANTIDADE DE ELEMENTOS DA MINHA LISTA
int tamanho(LISTA *li){
    if(li==NULL){
        return -1;//CASO MINHA LISTA NAO TENHA SIDO ALOCADA NA MEM�RIA, MINHA FUN��O RETORNAR� O VALOR -1
    }
    int cont=0;//VARIAVEL QUE CONTAR� A QUANTIDADE DE ELEMENTOS
    ELEM *aux = li->inicio;//CRIA UM PONTEIRO AUXILIAR PARA PERCORRER MINHA LISTA. DESTA FORMA, CADA PASSO DADO PELO ELEMENTO AXULIAR SER� UM ELEMENTO DA MINHA LISTA
    while(aux != NULL) //ENQUANTO O ELEMENTO AUXILIAR NAO APONTAR PARA NULL,
    {
        cont++;//INCREMENTA A MINHA LISTA (SE ELE ENTROU NO WHILE NA PRIMEIRA INTERA��O, SIGNIFICA QUE H� PELO MENOS UM ELEMENTO DA LISTA
        aux= aux->prox;//NESTE MOMENTO, N� RECEBERA O ENDERE�O QUE EST� NO CAMPO PR�XIMO.
    }//SE ELE FOR IGUAL A NULL. TERMINA O LA�O. SE NAO, SER� CONTABILIZADO UM NOVO ELEMENTO.
    return cont;//FUN��O RETORNA A QUANTIRADE DE ELEMENTOS
}

//FUN��O QUE VERIFICA SE LISTA EST� VAZIA OU NAO
void vazia(LISTA *li){
    int tam = tamanho(li);//ESTA PARTE PODE SER CONSIDERADA OPCIONAL. APENAS APRESENTAR� A QUANTIDADE DE ELEMENTOS DA MINHA LISTA (FUN��O TAMANHO)
    if(li !=NULL)  //SE A LISTA FOR ALOCADO...
    {
        if(li->inicio==NULL)  //VERIFICA SE O CAMPO INICIO APONTA PARA NULL. CASO APONTO, A LISTA ESTAR� VAZIA.
        {
            printf("\nLISTA VAZIA\n");
        }else    //SE NAO APONTAR, PARA NULL, TER� ELEMENTOS...
        {
            printf("\nLISTA NAO VAZIA\n");
        }
        printf("\nLISTA COM %d ELEMENTO(S)\n",tam);//APRESENTA A QUANTIDADE DE ELEMENTOS
    }
    else    //CASO MINHA LISTA NAO TENHA SIDO ALOCADA...
    {
        printf("\nERRO DE ALOCACAO\n");
    }
}

//FUN��O QUE IR� INSERIR UM NOVO ELEMENTO NA MINHA LISTA
void inserir(LISTA *li, ALUNO a) //COMO PAR�METROS DA FUN��O, TEREMOS: O ENDERE�O DA LISTA ; E OS DADOS DO ALUNO (QUE SER�O ARMAZENADOS NA MINHA STRUCT ALUNO)
{
    if(li==NULL) //CASO A LISTA NAO TENHA SIDO ALOCADA...
    {
        printf("\nERRO DE ALOCACAO\n");
    }
    else  //LISTA ALOCADA
    {
        ELEM *novo = (ELEM*) malloc(sizeof(ELEM));//NESTE PASSO, SER� CRIADO UM NOVO ELEMENTO VAZIO (CRIADO APENAS O ESPA�O NA MEM�RIA)
        if(novo != NULL) //CASO A ALOCA��O DESTE NOVO ELEMENTO TENHA SIDO FEITA
        {
            novo->dados= a;//O CAMPO DADOS, DA MINHA ESTRUTURA ELEMENTO RECEBE OS DADOS DO ALUNO PASSADO POR PAR�METRO DA FUN��O
            if(li->inicio==NULL){//LISTA VAZIA
                novo->prox=NULL;
                li->inicio=novo;
            }else{//LISTA NAO VAZIA
                ELEM *aux=li->inicio;
                if(aux->dados.codigo > novo->dados.codigo){//INSER��O NO INICIO
                    novo->prox=aux;
                    li->inicio=novo;
                }else{//INSER��O NO MEIO OU FIM
                    ELEM *ant;
                    while((aux!=NULL)&&(aux->dados.codigo < novo->dados.codigo)){
                        ant=aux;
                        aux=aux->prox;
                    }
                    ant->prox=novo;
                    novo->prox=aux;
                }

            }
            printf("\nELEMENTO INSERIDO\n");
        }
        else  //SE MINHA LISTA NAO ESTIVER ALOCADA...
        {
            printf("\nERRO DE ALOCACAO\n");
        }
    }
}

//FUN�AO QUE REMOVER� UM ELEMENTO DA LISTA. O ELEMENTO A SER REMOVIDO SERA PASSADO POR PARAMETRO

void remover(LISTA *li, int cod){
    if(li==NULL) //SE A LISTA NAO FOR ALOCADA...
    {
        printf("\nERRO DE ALOCACAO\n");
    }
    else  //LISTA ALOCADA...
    {
        if(li->inicio==NULL) //SE O CAMPO IN�CIO APONTAR PARA NULL, SIGNIFICA QUE A LISTA EST� VAZIA
        {
            printf("\nLISTA VAZIA\n");
        }
        else  //SE NAO ESTIVER VAZIA...
        {
            ELEM *aux=li->inicio;
            if(aux->dados.codigo==cod){//SE O ELEMENTO FOR O PRIMEIRO DA LISTA
                li->inicio=aux->prox;
                free(aux);
            }else{//O ELEMENTO NAO ESTA NO INICIO DA LISTA
                ELEM *ant;
                while((aux!=NULL)&&(aux->dados.codigo != cod)){
                    ant=aux;
                    aux=aux->prox;
                }
                if(aux==NULL){
                    return;
                }
                ant->prox = aux->prox;
                free(aux);
            }
            printf("\nELEMENTO REMOVIDO\n");
        }
    }
}

//FUN��O QUE APRESENTAR� OS ALUNOS ARMAZENADOS NA LISTA
void mostrar(LISTA *li)
{
    if(li == NULL)  //SE A LISTA NAO FOR ALOCADA....
    {
        printf("\nERRO DE ALOCACAO\n");
    }
    else    //LISTA ALOCADA...
    {
        if(li->inicio==NULL)  //SE O CAMPO FIM FOR IGUAL NULL, A LISTA ESTAR� VAZIA. PODERIA TESTAR TAMB�M A POSI��O INICIAL. TANTO FAZ...
        {
            printf("\nLISTA VAZIA\n");
        }else{//H� ELEMENTO NA LISTA
            ELEM* aux = li->inicio;//CRIA-SE UM ELEMENTO AUXILIAR PARA PERCORRER A LISTA. RECER� O ENDERE�O DO PRIMEIRO ELEMENTO DA LISTA
            while(aux != NULL){
                printf("CODIGO: %d\n",aux->dados.codigo);//APRESENTA A MATRICULA DO ALUNO
                printf("NOME: %s\n",aux->dados.nome);//APRESENTA O NOME DO ALUNO
                printf("NOTAS: %.2f %.2f\n",aux->dados.n1, aux->dados.n2);//AS NOTAS 1 E 2 DO ALUNO
                printf("-------------------------------\n");//IMPRIME UMA LINHA DIVIS�RIA
                aux = aux->prox;//O ELEMENTO AUXILIAR RECEBE O ENDERE�O DO PR�XIMO ELEMENTO
            }//SE ELE FOR DIFERENTE DE NULL, SIGNIFICA QUE H� ELEMENTO NA LISTA. O PROCESSO DE IMPRESS�O SE REPETE
        }
    }
}

//FUN��O DE MENU QUE RETONA A OP��O ESCOLHIDA
int menu()
{
    int op;
    printf("\n0 - SAIR\n");
    printf("1 - MOSTRAR LISTA\n");
    printf("2 - VERIFICAR LISTA VAZIA\n");
    printf("3 - TAMANHO DA LISTA\n");
    printf("4 - INSERIR\n");
    printf("5 - REMOVER\n");
    printf("\nOPCAO: ");
    scanf("%d",&op);
    putchar('\n');
    system("cls");
    return op;//INTEIRO COM A OP��O ESCOLHIDA

}

//FUN��O QUE IR� LER OS DADOS DO ALUNO E ARMAZENAR� NA STRUCT ALUNO

void novoAluno(ALUNO *a) //RECEBE COMO PAR�METRO O ENDERE�O DA ESTRUTURA ALUNO
{
    printf("DIGITE A MATRICULA: ");
    scanf("%d",&a->codigo);//ADICIONA O CONTE�DO AO CAMPO CODIGO
    printf("DIGITE NOME: ");
    fflush(stdin);//LIMPA O BUFFER DO TECLADO (COMANDO PARA WINDOWS)
    gets(a->nome);//ADICIONA O CONTE�DO AO CAMPO NOME
    printf("DIGITE A NOTA 1: ");
    scanf("%f",&a->n1);//ADICIONA O CONTE�DO AO CAMPO NOTA 1
    printf("DIGITE A NOTA 2: ");
    scanf("%f",&a->n2);//ADICIONA O CONTE�DO AO CAMPO NOTA 2
}

//FUN��O MAIN..
main()
{
    int o, cod;//VARIAVEL PARA RECEBER A OP��O DIGITADA PELO USU�RIO, E VARIAVAL DO CODIGO DE REMOCAO
    LISTA *li = criar();//CRIA UM PONTEIRO PARA LISTA, QUE RECEBE O ENDERE�O DA LISTA RETORNADO PELA FUN��O CRIAR();
    //O "TIPO" DO PONTEIRO SER� UMA ESTRUTURA: STRUCT LISTA.
    ALUNO a;//CRIA UMA ESTRUTURA DO "TIPO" STRUCT ALUNO.
    while((o=menu())!=0)
    {
        switch(o)
        {
        case 0://OPCAO PARA TERMINAR O LA�O E SAIR DO PROGRAMA
            break;
        case 1://OP��O QUE MOSTRA OS ELEMENTOS DA LISTA
            mostrar(li);//CHAMA A FUN��O MOSTRAR. PAR�METRO: ENDERE�O DA LISTA CRIADA (FI � UM PONTEIRO)
            break;
        case 2:
            vazia(li);//OP��O EU VERIFICA SE A LISTA EST� VAZIA.PAR�METRO: ENDERE�O DA LISTA CRIADA
            break;
        case 3:
            printf("\nLISTA COM %d ELEMENTO(S)\n",tamanho(li));
            break;
        case 4:
            novoAluno(&a);//CHAMA A FUN��O QUE LER OS CAMPOS DA ESTRUTURA ALUNO. (VEJA QUE SER� PASSADO O ENDERE�O DA ESTRUTURA CRIADA)
            inserir(li,a);//CHAMA A FUN��O QUE INSERE UM ELEMENTO NA LISTA. PAR�MENTROS: ENDERE�O DA LISTA CRIADA E OS DADOS DE ALUNOS RECEM DIGITADOS
            break;
        case 5://OP��O PARA REMO��O DO PRIMEIRO ELEMENTO DA LISTA.
            mostrar(li);
            printf("DIGITE O CODIGO DO ALUNO QUE SERA REMOVIDO >> ");
            scanf("%d",&cod);
            remover(li,cod);//CHAMA A FUN��O DE REMO�AO. PAR�METRO: ENDERE�O DA LISTA CRIADA
            break;
        default:
            printf("OPCAO INVALIDA\n\n");
        }
    }
    liberar(li); //AP�S SAIR DO LA�O, SER� CHAMADA A FUN��O QUE DESALOCA O ESPA�O DE MEM�RIA PARA LISTA.
}
