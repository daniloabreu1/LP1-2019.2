#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
AUTOR: DANILO ABREU SANTOS
ESTE PROGRAMA IMPLEMENTA A ESTRUTURA DE DADOS PILHA DE FORMA DIN�MICA.

A PILHA SEGUE A REGRA LIFO (LAST IN, FIRST OUT), OU SEJA, O �LTIMO ELEMENTO INSERIDO
SER� O PRIMEIRO A SER REMOVIDO.

A MANIPULA��O DA PILHA SE DAR� APENAS EM SEU TOPO: OS NOVOS ELEMENTOS SER�O INSERIDOS NO TOPO DA PILHA,
ASSIM COMO A SUA REMO��O

NO PROGRAMA ABAIXO SAO IMPLEMENTADAS AS TAREFAS DE:

--> CRIAR UMA PILHA
--> INSERIR ELEMENTOS EM UMA PILHA
--> REMOVER ELEMENTOS EM UMA PILHA
--> VERIpiCAR SE A PILHA EST� VAZIA
--> VERIpiCAR A QUANTIDADE DE ELEMENTOS DA PILHA
--> IMPRIMIR A PILHA
--> LIBERAR O ESPA�O DE MEM�RIA ALOCADA PARA PILHA E SEUS ELEMENTOS

*/
int matricula =1000;//VARIAVEL GLOBAL PARA MATRICULA

//ESTRUTURA QUE ARMAZENARA OS DADOS DO ALUNO
typedef struct
{
    char nome[31];
    int mat;
    float n1, n2,media;
}ALUNO;

//ESTRUTURA QUE RECEBER� O CONJUNTO DE DADOS DO ALUNO E O ENDERE�O DO PROXIMO ELEMENTO DA PILHA (O ALUNO A SEGUIR)
typedef struct elemento
{
    ALUNO dados;//AQUI, SER� ARMAZENADOS OS DADOS DO ALUNO
    struct elemento *prox;//ESTE CAMPO SER� UM PONTEIRO PARA O PR�XIMO ELEMENTO DA PILHA (QUE TAMB�M SER� DO "TIPO" STRUCT ELEMENTO)
} ELEM;

//A ESTRUTURA ABAIXO SER� O TOPO DA PILHA
typedef struct
{
    ELEM *topo; //ESTRUTURA QUE RECEBER� O �LTIMO ELEMENTO (DADOS DO ALUNO E PROXIMO ELEMENTO) DA PILHA
} PILHA;

//FUN��O QUE RETORNA O ENDERE�O DE MEM�RIA DE UMA PILHA VAZIA.
PILHA* criar()  //CRIA UMA FUN��O DO TIPO STRUCT PILHA
{
    PILHA* pi = (PILHA*) malloc(sizeof(PILHA)); //ALOCA O ESPA�O NA MEM�RIA
    if(pi != NULL) //SE O SISTEMA OPERACIONAL ALOCAR, ENTRA NO IF.
    {
        pi->topo= NULL; //INICIA O TOPO COM NULL
    }
    return pi;//RETORNA O ENDERE�O DA PILHA
}

void novoAluno(ALUNO *al) //RECEBE COMO PAR�METRO O ENDERE�O DA ESTRUTURA ALUNO
{
    al->mat=matricula++;
    printf("MATRICULA: %d\n",al->mat);
    printf("DIGITE NOME: ");
    fflush(stdin);//LIMPA O BUFFER DO TECLADO (COMANDO PARA WINDOWS)
    gets(al->nome);//ADICIONA O CONTE�DO AO CAMPO NOME
    strupr(al->nome);//SALVA O NOME EM MAI�SCULO
    printf("DIGITE A NOTA 1: ");
    scanf("%f",&al->n1);//ADICIONA O CONTE�DO AO CAMPO NOTA 1
    printf("DIGITE A NOTA 2: ");
    scanf("%f",&al->n2);//ADICIONA O CONTE�DO AO CAMPO NOTA 2
    al->media=(al->n1+al->n2)/2.0;
}


//FUN��O QUE IR� INSERIR UM NOVO ELEMENTO NA MINHA PILHA
void inserir(PILHA *pi, ALUNO al) //COMO PAR�METROS DA FUN��O, TEREMOS: O ENDERE�O DA PILHA ; E OS DADOS DO ALUNO (QUE SER�O ARMAZENADOS NA MINHA STRUCT ALUNO)
{
    if(pi==NULL) //CASO A PILHA NAO TENHA SIDO ALOCADA...
    {
        printf("\nERRO DE ALOCACAO\n");
    }
    else  //PILHA ALOCADA
    {
        ELEM *no = (ELEM*) malloc(sizeof(ELEM));//NESTE PASSO, SER� CRIADO UM NOVO ELEMENTO VAZIO (CRIADO APENAS O ESPA�O NA MEM�RIA)
        if(no != NULL) //CASO A ALOCA��O DESTE NOVO ELEMENTO TENHA SIDO FEITA
        {
            no->dados= al;//O CAMPO DADOS, DA MINHA ESTRUTURA ELEMENTO RECEBE OS DADOS DO ALUNO PASSADO POR PAR�METRO DA FUN��O

            //NO IF ABAIXO, TEREMOS AS DUAS POSSIBILIDADES DE INSERIR O NOVO ELEMENTO: PILHA VAZIA OU PILHA COM ELEMENTOS
            if(pi->topo==NULL) //SE O CAMPO TOPO DA MINHA PILHA APONTAR PARA NULL, SIGNIpiCA QUE MINHA PILHA ESTAR� VAZIA
            {
                no->prox= NULL;//COMO ESTE ELEMENTO � O PRIMEIRO A SER INSERIDO, O PR�XIMO DESTE ELEMENTO APONTAR� PARA NULL

            }
            else  //SE A MINHA PILHA NAO FOR VAZIA...
            {
                no->prox= pi->topo;
                //MAS O CAMPO PR�XIMO, DO ELEMENTO QUE ESTAVA COMO �LTIMO, PASSAR� A APONTAR PARA O ELEMENTO REC�M CRIADO
            }
            pi->topo=no;//ASSIM SENDO, O CAMPO TOPO APONTAR� PARA O ELEMENTO NO (QUE ACABOU DE SER CRIADO)
            printf("\nALUNO INSERIDO\n\n");
            mostrar(pi);
        }
        else  //SE MINHA PILHA NAO ESTIVER ALOCADA...
        {
            printf("\nERRO DE ALOCACAO\n");
        }
    }
}


//FUN�AO QUE REMOVER� UM ELEMENTO DA PILHA. VALE LEMBRAR QUE S� SER�O REMOVIDOS ELEMENTOS:
//QUANDO A PILHA NAO ESTIVER VAZIA; E SEMPRE REMOVER� O PRIMEIRO ELEMENTO (piFO)

void remover(PILHA *pi)
{
    if(pi==NULL) //SE A PILHA NAO FOR ALOCADA...
    {
        printf("\nERRO DE ALOCACAO\n");
    }
    else  //PILHA ALOCADA...
    {
        if(pi->topo==NULL) //SE O CAMPO IN�CIO APONTAR PARA NULL, SIGNIpiCA QUE A PILHA EST� VAZIA
        {
            printf("\nPILHA VAZIA\n");
        }
        else  //SE NAO ESTIVER VAZIA...
        {
            ELEM *no = pi->topo;//CRIA-SE UM ELEMENTO AUXILIZAR QUE RECEBE O ENDERE�O DO PRIMEIRO ELEMENTO DA PILHA
            pi->topo = pi->topo->prox;//NESTE PONTO, O CAMPO IN�CIO DA PILHA (O N�)
            //RECEBER� O ENDERE�O DO PR�XIMO ELEMENTO (O ELEMENTO QUE ESTAR� NA SEGUNDA POSI��O DA PILHA)
            char nome[30];
            int m = no->dados.mat;
            strcpy(nome,no->dados.nome);
            free(no);//NESTE PONTO, O ESPA�O ALOCADO PARA O PRIMEOR ELEMENTO SER� LIBERADO
            printf("\nALUNO %s, COM MATRICULA %d REMOVIDO\n\n",nome,m);
            mostrar(pi);
        }
    }
}



//FUN��O QUE APRESENTAR� OS ALUNOS ARMAZENADOS NA PILHA
void mostrar(PILHA *pi)
{
    if(pi == NULL)  //SE A PILHA NAO FOR ALOCADA....
    {
        printf("\nERRO DE ALOCACAO\n");
    }
    else    //PILHA ALOCADA...
    {
        if(pi->topo==NULL)  //SE O CAMPO TOPO FOR IGUAL NULL, A PILHA ESTAR� VAZIA. PODERIA TESTAR TAMB�M A POSI��O INICIAL. TANTO FAZ...
        {
            printf("\nPILHA VAZIA\n");
        }
        else    //H� ELEMENTO NA PILHA
        {
            ELEM* no = pi->topo;//CRIA-SE UM ELEMENTO AUXILIAR PARA PERCORRER A PILHA. RECER� O ENDERE�O DO PRIMEIRO ELEMENTO DA PILHA
            while(no != NULL)
            {
                printf("MATRICULA: %d\n",no->dados.mat);//APRESENTA A MATRICULA DO ALUNO
                printf("NOME: %s\n",no->dados.nome);//APRESENTA O NOME DO ALUNO
                printf("NOTAS: %.2f %.2f\n",no->dados.n1, no->dados.n2);//AS NOTAS 1 E 2 DO ALUNO
                printf("MEDIA: %.2f\n",no->dados.media);//APRESENTA A MEDIA DO ALUNO
                printf("-------------------------------\n");//IMPRIME UMA LINHA DIVIS�RIA
                no = no->prox;//O ELEMENTO AUXILIAR RECEBE O ENDERE�O DO PR�XIMO ELEMENTO
            }//SE ELE FOR DIFERENTE DE NULL, SIGNIpiCA QUE H� ELEMENTO NA PILHA. O PROCESSO DE IMPRESS�O SE REPETE
            printf("\nPILHA COM %d ELEMENTO(S)\n",tamanho(pi));
        }
    }
}


//FUN��O QUE DESALOCA O ESPA�O NA MEM�RIA DO S.O.
void liberar(PILHA *pi)
{
    if(pi !=NULL)
    {
        ELEM * no;//CRIA UM PONTEIRO DE UMA ESTRUTURA ELEMENTO, PARA SERVIR DE AUXILIAR PARA O PROCESSO DE LIBERA��O
        while(pi->topo!=NULL) //VERIFICA SE A POSI��O INICIA TEM ALGUMA ESTRUTURA. CASO TENHA, ENTRA NO IF
        {
            no = pi->topo;//A ESTRUTURA AUXLIAR RECEBE O ENDERE�O DO PRIMEIRO ELEMENTO DA MINHA PILHA.
            pi->topo = pi->topo->prox;//A POSI��O DE TOPO DA MINHA PILHA PASSA A APONTAR AO VALOR QUE ESTAVA NO CAMPO PROX�MO (APONTAR� AO SEGUNO ELEMENTO)
            free(no);//COM A POSI��O INICIAL APONTANDO PARA SEGUNDA POSI��O, A PRIMEIRA (QUE ESTAVA GUARDADA NO ELEMENTO AUXILIAR) SER� LIBERADA.
        }//SE A POSI��O DE TOPO APONTAR PARA NULL, SIGINIpiCA QUE NAO H� MAIS ELEMENTOS NA MINHA PILHA.
        free(pi);//O ESPA�O DE MEM�RIA ALOCADO PARA MINHA PILHA � LIBERADO.
    }
}

//FUN��O ABAIXO RETORNA UM INTEIRO COM A QUANTIDADE DE ELEMENTOS DA MINHA PILHA
int tamanho(PILHA *pi)
{
    if(pi==NULL)
    {
        return -1;//CASO MINHA PILHA NAO TENHA SIDO ALOCADA NA MEM�RIA, MINHA FUN��O RETORNAR� O VALOR -1
    }
    int cont=0;//VARIAVEL QUE CONTAR� A QUANTIDADE DE ELEMENTOS
    ELEM *no = pi->topo;//CRIA UM ELEMENTO AUXILIAR PARA PERCORRER MINHA PILHA. DESTA FORMA, CADA PASSO DADO PELO ELEMENTO AXULIAR SER� UM ELEMENTO DA MINHA PILHA
    while(no != NULL) //ENQUANTO O ELEMENTO AUXILIAR NAO APONTAR PARA NULL,
    {
        cont++;//INCREMENTA A MINHA PILHA (SE ELE ENTROU NO WHILE NA PRIMEIRA INTERA��O, SIGNIpiCA QUE H� PELO MENOS UM ELEMENTO DA PILHA
        no= no->prox;//NESTE MOMENTO, N� RECEBERA O ENDERE�O QUE EST� NO CAMPO PR�XIMO.
    }//SE ELE FOR IGUAL A NULL. TERMINA O LA�O. SE NAO, SER� CONTABILIZADO UM NOVO ELEMENTO.
    return cont;//FUN��O RETORNA A QUANTIRADE DE ELEMENTOS
}

//FUN��O QUE VERIpiCA SE PILHA EST� VAZIA OU NAO
void vazia(PILHA *pi)
{
    int tam = tamanho(pi);//ESTA PARTE PODE SER CONSIDERADA OPCIONAL. APENAS APRESENTAR� A QUANTIDADE DE ELEMENTOS DA MINHA PILHA (FUN��O TAMANHO)
    if(pi !=NULL)  //SE A PILHA FOR ALOCADO...
    {
        if(pi->topo==NULL)  //VERIpiCA SE O CAMPO topo APONTA PARA NULL. CASO APONTO, A PILHA ESTAR� VAZIA.
        {
            printf("\nPILHA VAZIA\n");
        }
        else    //SE NAO APONTAR, PARA NULL, TER� ELEMENTOS...
        {
            printf("\nPILHA NAO VAZIA\n");
        }
        printf("\nPILHA COM %d ELEMENTO(S)\n",tam);//APRESENTA A QUANTIDADE DE ELEMENTOS
    }
    else    //CASO MINHA PILHA NAO TENHA SIDO ALOCADA...
    {
        printf("\nERRO DE ALOCACAO\n");
    }
}


//FUN��O DE MENU QUE RETONA A OP��O ESCOLHIDA
char menu()
{
    char op;
    printf("\t\tPILHA DINAMICA\n");
    printf("\nI - INSERIR ELEMENTOS\n");
    printf("M - MOSTRAR ELEMENTOS DA PILHA\n");
    printf("V - VERIFICAR PILHA VAZIA\n");
    printf("R - REMOVER ELEMENTOS\n");
    printf("S - SAIR\n");
    printf("\nOPCAO: ");
    scanf("%c",&op);
    putchar('\n');
    op=toupper(op);
    return op;//INTEIRO COM A OP��O ESCOLHIDA
}

//FUN��O QUE IR� LER OS DADOS DO ALUNO E ARMAZENAR� NA STRUCT ALUNO

//FUN��O MAIN..
main()
{
    char o;//VARIAVEL PARA RECEBER A OP��O DIGITADA PELO USU�RIO
    PILHA *pi = criar();//CRIA UM PONTEIRO PARA PILHA, QUE RECEBE O ENDERE�O DA PILHA RETORNADO PELA FUN��O CRIAR();
    //O "TIPO" DO PONTEIRO SER� UMA ESTRUTURA: STRUCT PILHA.
    ALUNO al;//CRIA UMA ESTRUTURA DO "TIPO" STRUCT ALUNO.
    while((o=menu())!='S')
    {
        switch(o)
        {
        case 'S'://OPCAO PARA TERMINAR O LA�O E SAIR DO PROGRAMA
            break;
        case 'M'://OP��O QUE MOSTRA OS ELEMENTOS DA PILHA
            system("cls");
            mostrar(pi);//CHAMA A FUN��O MOSTRAR. PAR�METRO: ENDERE�O DA PILHA CRIADA (pi � UM PONTEIRO)
            break;
        case 'V':
            system("cls");
            vazia(pi);//OP��O EU VERIpiCA SE A PILHA EST� VAZIA.PAR�METRO: ENDERE�O DA PILHA CRIADA
            break;
        case 'I':
            system("cls");
            novoAluno(&al);//CHAMA A FUN��O QUE LER OS CAMPOS DA ESTRUTURA ALUNO. (VEJA QUE SER� PASSADO O ENDERE�O DA ESTRUTURA CRIADA)
            inserir(pi,al);//CHAMA A FUN��O QUE INSERE UM ELEMENTO NA PILHA. PAR�MENTROS: ENDERE�O DA PILHA CRIADA E OS DADOS DE ALUNOS RECEM DIGITADOS
            break;
        case 'R'://OP��O PARA REMO��O DO PRIMEIRO ELEMENTO DA PILHA.
            system("cls");
            remover(pi);//CHAMA A FUN��O DE REMO�AO. PAR�METRO: ENDERE�O DA PILHA CRIADA
            break;
        default:
            printf("OPCAO INVALIDA\n\n");
        }
        printf("\n\nPRESSIONE QUALQUER TECLA PARA CONTINUAR...\n\n");
        fflush(stdin);
        getchar();
        system("cls");
    }
    liberar(pi); //AP�S SAIR DO LA�O, SER� CHAMADA A FUN��O QUE DESALOCA O ESPA�O DE MEM�RIA PARA PILHA.
}
