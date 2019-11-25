#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
ESTE PROGRAMA IMPLEMENTA A ESTRUTURA DE DADOS LISTA DUPLAMENTE ENCADEADA.

TANTO A INSERÇÃO QUANTO A REMOÇAO PODERAO SER EM QUALQUER PARTE DA LISTA

NO PROGRAMA ABAIXO SAO IMPLEMENTADAS AS TAREFAS DE:

--> CRIAR UMA LISTA
--> INSERIR ELEMENTOS EM UMA LISTA DE FORMA ORDENADA
--> REMOVER ELEMENTOS EM UMA LISTA
--> VERIFICAR SE A LISTA ESTÁ VAZIA
--> VERIFICAR A QUANTIDADE DE ELEMENTOS DA LISTA
--> IMPRIMIR A LISTA
--> LIBERAR O ESPAÇO DE MEMÓRIA ALOCADA PARA LISTA E SEUS ELEMENTOS

*/

//ESTRUTURA QUE ARMAZENARA OS DADOS DO CONTATO
typedef struct {
    char nome[31];
    char telefone[18];
}CONTATO;

//ESTRUTURA QUE RECEBERÁ O CONJUNTO DE DADOS DO CONTATO E O ENDEREÇO DO PROXIMO ELEMENTO DA LISTA (O CONTATO A SEGUIR)
typedef struct elemento{
    CONTATO dados;//AQUI, SERÁ ARMAZENADOS OS DADOS DO CONTATO
    struct elemento *ant;//ESTE CAMPO SERÁ UM PONTEIRO PARA O ANTERIOR ELEMENTO DA LISTA (QUE TAMBÉM SERÁ DO "TIPO" STRUCT ELEMENTO)
    struct elemento *prox;//ESTE CAMPO SERÁ UM PONTEIRO PARA O PRÓXIMO ELEMENTO DA LISTA (QUE TAMBÉM SERÁ DO "TIPO" STRUCT ELEMENTO)
} ELEM;

//A ESTRUTURA ABAIXO TERA O APONTADOR DO PRIMEIRO ELEMENTO DA LISTA
typedef struct{
    ELEM *inicio; //ESTRUTURA QUE RECEBERÁ O PRIMEIRO ELEMENTO (DADOS DO CONTATO E PROXIMO ELEMENTO) DA LISTA
}LISTA;

//FUNÇÃO QUE RETORNA O ENDEREÇO DE MEMÓRIA DE UMA LISTA VAZIA.
LISTA* criar(){
    LISTA* li = (LISTA*) malloc(sizeof(LISTA)); //ALOCA O ESPAÇO NA MEMÓRIA
    if(li != NULL) //SE O SISTEMA OPERACIONAL ALOCAR, ENTRA NO IF.
    {
        li->inicio= NULL; //INICIA A POSIÇÃO INICIAL COM NULL
    }
    return li;//RETORNA O ENDEREÇO DA LISTA
}

//FUNÇÃO QUE DESALOCA O ESPAÇO NA MEMÓRIA DO S.O.
void liberar(LISTA *li){
    if(li !=NULL){
        ELEM * aux;//CRIA UM PONTEIRO DE UMA ESTRUTURA ELEMENTO, PARA SERVIR DE AUXILIAR PARA O PROCESSO DE LIBERAÇÃO
        while(li->inicio!=NULL) //VERIFICA SE A POSIÇÃO INICIA TEM ALGUMA ESTRUTURA. CASO TENHA, ENTRA NO IF
        {
            aux = li->inicio;//O PONTEIRO AUXLIAR RECEBE O ENDEREÇO DO PRIMEIRO ELEMENTO DA MINHA LISTA.
            li->inicio = li->inicio->prox;//A POSIÇÃO DE INICIO DA MINHA LISTA PASSA A APONTAR AO VALOR QUE ESTAVA NO CAMPO PROXÍMO (APONTARÁ AO SEGUNO ELEMENTO)
            free(aux);//COM A POSIÇÃO INICIAL APONTANDO PARA SEGUNDA POSIÇÃO, A PRIMEIRA (QUE ESTAVA GUARDADA NO ELEMENTO AUXILIAR) SERÁ LIBERADA.
        }//SE A POSIÇÃO DE INICIO APONTAR PARA NULL, SIGINIFICA QUE NAO HÁ MAIS ELEMENTOS NA MINHA LISTA.
        free(li);//O ESPAÇO DE MEMÓRIA ALOCADO PARA MINHA LISTA É LIBERADO.
    }
}

//FUNÇÃO ABAIXO RETORNA UM INTEIRO COM A QUANTIDADE DE ELEMENTOS DA MINHA LISTA
int tamanho(LISTA *li){
    if(li==NULL){
        return -1;//CASO MINHA LISTA NAO TENHA SIDO ALOCADA NA MEMÓRIA, MINHA FUNÇÃO RETORNARÁ O VALOR -1
    }
    int cont=0;//VARIAVEL QUE CONTARÁ A QUANTIDADE DE ELEMENTOS
    ELEM *aux = li->inicio;//CRIA UM PONTEIRO AUXILIAR PARA PERCORRER MINHA LISTA. DESTA FORMA, CADA PASSO DADO PELO ELEMENTO AXULIAR SERÁ UM ELEMENTO DA MINHA LISTA
    while(aux != NULL) //ENQUANTO O ELEMENTO AUXILIAR NAO APONTAR PARA NULL,
    {
        cont++;//INCREMENTA A MINHA LISTA (SE ELE ENTROU NO WHILE NA PRIMEIRA INTERAÇÃO, SIGNIFICA QUE HÁ PELO MENOS UM ELEMENTO DA LISTA
        aux= aux->prox;//NESTE MOMENTO, NÓ RECEBERA O ENDEREÇO QUE ESTÁ NO CAMPO PRÓXIMO.
    }//SE ELE FOR IGUAL A NULL. TERMINA O LAÇO. SE NAO, SERÁ CONTABILIZADO UM NOVO ELEMENTO.
    return cont;//FUNÇÃO RETORNA A QUANTIRADE DE ELEMENTOS
}

//FUNÇÃO QUE VERIFICA SE LISTA ESTÁ VAZIA OU NAO
void vazia(LISTA *li){
    int tam = tamanho(li);//ESTA PARTE PODE SER CONSIDERADA OPCIONAL. APENAS APRESENTARÁ A QUANTIDADE DE ELEMENTOS DA MINHA LISTA (FUNÇÃO TAMANHO)
    if(li !=NULL)  //SE A LISTA FOR ALOCADO...
    {
        if(li->inicio==NULL)  //VERIFICA SE O CAMPO INICIO APONTA PARA NULL. CASO APONTO, A LISTA ESTARÁ VAZIA.
        {
            printf("\nLISTA VAZIA\n");
        }else    //SE NAO APONTAR, PARA NULL, TERÁ ELEMENTOS...
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

//FUNÇÃO QUE IRÁ INSERIR UM NOVO ELEMENTO NA MINHA LISTA
void inserir(LISTA *li, CONTATO c) //COMO PARÂMETROS DA FUNÇÃO, TEREMOS: O ENDEREÇO DA LISTA ; E OS DADOS DO CONTATO (QUE SERÃO ARMAZENADOS NA MINHA STRUCT CONTATO)
{
    if(li==NULL) //CASO A LISTA NAO TENHA SIDO ALOCADA...
    {
        printf("\nERRO DE ALOCACAO\n");
    }
    else  //LISTA ALOCADA
    {
        ELEM *novo = (ELEM*) malloc(sizeof(ELEM));//NESTE PASSO, SERÁ CRIADO UM NOVO ELEMENTO VAZIO (CRIADO APENAS O ESPAÇO NA MEMÓRIA)
        if(novo != NULL) //CASO A ALOCAÇÃO DESTE NOVO ELEMENTO TENHA SIDO FEITA
        {
            novo->dados= c;//O CAMPO DADOS, DA MINHA ESTRUTURA ELEMENTO RECEBE OS DADOS DO CONTATO PASSADO POR PARÂMETRO DA FUNÇÃO
            if(li->inicio==NULL){//LISTA VAZIA
                novo->prox=NULL;
                novo->ant=NULL;
                li->inicio=novo;
            }else{//LISTA NAO VAZIA
                if(strcmp(li->inicio->dados.nome,novo->dados.nome)>0){//INSERÇÃO NO INICIO
                    novo->ant=NULL;
                    novo->prox=li->inicio;
                    li->inicio->ant=novo;
                    li->inicio=novo;
                }else{//INSERÇÃO NO MEIO OU FIM
                    ELEM *ante,*aux=li->inicio;
                    while((aux!=NULL)&&(strcmp(aux->dados.nome,novo->dados.nome)<=0)){
                        ante=aux;
                        aux=aux->prox;
                    }
                    ante->prox=novo;
                    novo->ant=ante;
                    novo->prox=aux;
                    if(aux!=NULL)
                        aux->ant=novo;
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

//FUNÇAO QUE REMOVERÁ UM ELEMENTO DA LISTA. O ELEMENTO A SER REMOVIDO SERA PASSADO POR PARAMETRO

void remover(LISTA *li, int pos){
    if(li==NULL) //SE A LISTA NAO FOR ALOCADA...
    {
        printf("\nERRO DE ALOCACAO\n");
    }
    else  //LISTA ALOCADA...
    {
        if(li->inicio==NULL) //SE O CAMPO INÍCIO APONTAR PARA NULL, SIGNIFICA QUE A LISTA ESTÁ VAZIA
        {
            printf("\nLISTA VAZIA\n");
        }
        else  //SE NAO ESTIVER VAZIA...
        {
            ELEM *aux=li->inicio;
            int cont=1;
            if(cont==pos){//SE O ELEMENTO FOR O PRIMEIRO DA LISTA
                li->inicio=aux->prox;
                if(aux->prox!=NULL)
                    aux->prox->ant=NULL;
                free(aux);
            }else{//O ELEMENTO NAO ESTA NO INICIO DA LISTA
                ELEM *ant;
                while((aux!=NULL)&&(cont != pos)){
                    ant=aux;
                    aux=aux->prox;
                    cont++;
                }
                if(aux==NULL){
                    return;
                }
                ant->prox = aux->prox;
                if(aux->prox!=NULL)
                    aux->prox->ant=ant;
                free(aux);
            }
            printf("\nELEMENTO REMOVIDO\n");
        }
    }
}

//FUNÇÃO QUE APRESENTARÁ OS CONTATOS ARMAZENADOS NA LISTA
void mostrar(LISTA *li)
{
    if(li == NULL)  //SE A LISTA NAO FOR ALOCADA....
    {
        printf("\nERRO DE ALOCACAO\n");
    }
    else    //LISTA ALOCADA...
    {
        if(li->inicio==NULL)  //SE O CAMPO FIM FOR IGUAL NULL, A LISTA ESTARÁ VAZIA. PODERIA TESTAR TAMBÉM A POSIÇÃO INICIAL. TANTO FAZ...
        {
            printf("\nLISTA VAZIA\n");
        }else{//HÁ ELEMENTO NA LISTA
            int cont=0;//VARIAVEL PARA CONTAR OS CONTATOS
            ELEM* aux = li->inicio;//CRIA-SE UM ELEMENTO AUXILIAR PARA PERCORRER A LISTA. RECERÁ O ENDEREÇO DO PRIMEIRO ELEMENTO DA LISTA
            printf("#\tNOME\t\tTELEFONE\n");
            while(aux != NULL){
                cont++;
                printf("%d\t%s\t\t",cont,aux->dados.nome);//APRESENTA O NOME DO CONTATO
                printf("%s\n",aux->dados.telefone);//APRESENTA O NOME DO CONTATo
                aux = aux->prox;//O ELEMENTO AUXILIAR RECEBE O ENDEREÇO DO PRÓXIMO ELEMENTO
            }//SE ELE FOR DIFERENTE DE NULL, SIGNIFICA QUE HÁ ELEMENTO NA LISTA. O PROCESSO DE IMPRESSÃO SE REPETE
        }
    }
}

//FUNÇÃO DE MENU QUE RETONA A OPÇÃO ESCOLHIDA
int menu()
{
    int op;
    printf("\n0 - SAIR\n");
    printf("1 - MOSTRAR LISTA DE CONTATOS\n");
    printf("2 - VERIFICAR LISTA VAZIA\n");
    printf("3 - TAMANHO DA LISTA\n");
    printf("4 - INSERIR\n");
    printf("5 - REMOVER\n");
    printf("\nOPCAO: ");
    scanf("%d",&op);
    putchar('\n');
    system("cls");
    return op;//INTEIRO COM A OPÇÃO ESCOLHIDA

}

//FUNÇÃO QUE IRÁ LER OS DADOS DO CONTATO E ARMAZENARÁ NA STRUCT CONTATO

void novoContato(CONTATO *c) //RECEBE COMO PARÂMETRO O ENDEREÇO DA ESTRUTURA CONTATO
{
    printf("DIGITE O NOME DO CONTATO: ");
    setbuf(stdin,NULL);//LIMPA O BUFFER DO TECLADO (COMANDO PARA WINDOWS)
    gets(c->nome);//ADICIONA O CONTEÚDO AO CAMPO NOME
    printf("DIGITE O TELEFONE (XX)XXXXX-XXXX: ");
    setbuf(stdin,NULL);
    gets(c->telefone);//ADICIONA O TELEFONE DO CONTATO

}

//FUNÇÃO MAIN..
main()
{
    int o, pos;//VARIAVEL PARA RECEBER A OPÇÃO DIGITADA PELO USUÁRIO, E VARIAVAL COM A POSICAO DO CONTATO A SER REMOVIDO
    LISTA *li = criar();//CRIA UM PONTEIRO PARA LISTA, QUE RECEBE O ENDEREÇO DA LISTA RETORNADO PELA FUNÇÃO CRIAR();
    //O "TIPO" DO PONTEIRO SERÁ UMA ESTRUTURA: STRUCT LISTA.
    CONTATO c;//CRIA UMA ESTRUTURA DO "TIPO" STRUCT CONTATO.
    while((o=menu())!=0)
    {
        switch(o)
        {
        case 0://OPCAO PARA TERMINAR O LAÇO E SAIR DO PROGRAMA
            break;
        case 1://OPÇÃO QUE MOSTRA OS ELEMENTOS DA LISTA
            mostrar(li);//CHAMA A FUNÇÃO MOSTRAR. PARÂMETRO: ENDEREÇO DA LISTA CRIADA (FI É UM PONTEIRO)
            break;
        case 2:
            vazia(li);//OPÇÃO EU VERIFICA SE A LISTA ESTÁ VAZIA.PARÂMETRO: ENDEREÇO DA LISTA CRIADA
            break;
        case 3:
            printf("\nLISTA COM %d ELEMENTO(S)\n",tamanho(li));
            break;
        case 4:
            novoContato(&c);//CHAMA A FUNÇÃO QUE LER OS CAMPOS DA ESTRUTURA CONTATO. (VEJA QUE SERÁ PASSADO O ENDEREÇO DA ESTRUTURA CRIADA)
            inserir(li,c);//CHAMA A FUNÇÃO QUE INSERE UM ELEMENTO NA LISTA. PARÂMENTROS: ENDEREÇO DA LISTA CRIADA E OS DADOS DE CONTATOS RECEM DIGITADOS
            break;
        case 5://OPÇÃO PARA REMOÇÃO DO PRIMEIRO ELEMENTO DA LISTA.
            mostrar(li);
            printf("DIGITE O CODIGO DO CONTATO QUE SERA REMOVIDO >> ");
            scanf("%d",&pos);
            remover(li,pos);//CHAMA A FUNÇÃO DE REMOÇAO. PARÂMETRO: ENDEREÇO DA LISTA CRIADA
            break;
        default:
            printf("OPCAO INVALIDA\n\n");
        }
    }
    liberar(li); //APÓS SAIR DO LAÇO, SERÁ CHAMADA A FUNÇÃO QUE DESALOCA O ESPAÇO DE MEMÓRIA PARA LISTA.
}
