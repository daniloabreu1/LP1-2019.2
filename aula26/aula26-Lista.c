#include <stdio.h>
#include <stdlib.h>
/*
ESTE PROGRAMA IMPLEMENTA A ESTRUTURA DE DADOS LISTA.

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

//ESTRUTURA QUE ARMAZENARA OS DADOS DO ALUNO
typedef struct {
    char nome[31];
    int codigo;
    float n1, n2;
}ALUNO;

//ESTRUTURA QUE RECEBERÁ O CONJUNTO DE DADOS DO ALUNO E O ENDEREÇO DO PROXIMO ELEMENTO DA LISTA (O ALUNO A SEGUIR)
typedef struct elemento{
    ALUNO dados;//AQUI, SERÁ ARMAZENADOS OS DADOS DO ALUNO
    struct elemento *prox;//ESTE CAMPO SERÁ UM PONTEIRO PARA O PRÓXIMO ELEMENTO DA LISTA (QUE TAMBÉM SERÁ DO "TIPO" STRUCT ELEMENTO)
} ELEM;

//A ESTRUTURA ABAIXO TERA O APONTADOR DO PRIMEIRO ELEMENTO DA LISTA
typedef struct{
    ELEM *inicio; //ESTRUTURA QUE RECEBERÁ O PRIMEIRO ELEMENTO (DADOS DO ALUNO E PROXIMO ELEMENTO) DA LISTA
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
void inserir(LISTA *li, ALUNO a) //COMO PARÂMETROS DA FUNÇÃO, TEREMOS: O ENDEREÇO DA LISTA ; E OS DADOS DO ALUNO (QUE SERÃO ARMAZENADOS NA MINHA STRUCT ALUNO)
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
            novo->dados= a;//O CAMPO DADOS, DA MINHA ESTRUTURA ELEMENTO RECEBE OS DADOS DO ALUNO PASSADO POR PARÂMETRO DA FUNÇÃO
            if(li->inicio==NULL){//LISTA VAZIA
                novo->prox=NULL;
                li->inicio=novo;
            }else{//LISTA NAO VAZIA
                ELEM *aux=li->inicio;
                if(aux->dados.codigo > novo->dados.codigo){//INSERÇÃO NO INICIO
                    novo->prox=aux;
                    li->inicio=novo;
                }else{//INSERÇÃO NO MEIO OU FIM
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

//FUNÇAO QUE REMOVERÁ UM ELEMENTO DA LISTA. O ELEMENTO A SER REMOVIDO SERA PASSADO POR PARAMETRO

void remover(LISTA *li, int cod){
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

//FUNÇÃO QUE APRESENTARÁ OS ALUNOS ARMAZENADOS NA LISTA
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
            ELEM* aux = li->inicio;//CRIA-SE UM ELEMENTO AUXILIAR PARA PERCORRER A LISTA. RECERÁ O ENDEREÇO DO PRIMEIRO ELEMENTO DA LISTA
            while(aux != NULL){
                printf("CODIGO: %d\n",aux->dados.codigo);//APRESENTA A MATRICULA DO ALUNO
                printf("NOME: %s\n",aux->dados.nome);//APRESENTA O NOME DO ALUNO
                printf("NOTAS: %.2f %.2f\n",aux->dados.n1, aux->dados.n2);//AS NOTAS 1 E 2 DO ALUNO
                printf("-------------------------------\n");//IMPRIME UMA LINHA DIVISÓRIA
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
    printf("1 - MOSTRAR LISTA\n");
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

//FUNÇÃO QUE IRÁ LER OS DADOS DO ALUNO E ARMAZENARÁ NA STRUCT ALUNO

void novoAluno(ALUNO *a) //RECEBE COMO PARÂMETRO O ENDEREÇO DA ESTRUTURA ALUNO
{
    printf("DIGITE A MATRICULA: ");
    scanf("%d",&a->codigo);//ADICIONA O CONTEÚDO AO CAMPO CODIGO
    printf("DIGITE NOME: ");
    fflush(stdin);//LIMPA O BUFFER DO TECLADO (COMANDO PARA WINDOWS)
    gets(a->nome);//ADICIONA O CONTEÚDO AO CAMPO NOME
    printf("DIGITE A NOTA 1: ");
    scanf("%f",&a->n1);//ADICIONA O CONTEÚDO AO CAMPO NOTA 1
    printf("DIGITE A NOTA 2: ");
    scanf("%f",&a->n2);//ADICIONA O CONTEÚDO AO CAMPO NOTA 2
}

//FUNÇÃO MAIN..
main()
{
    int o, cod;//VARIAVEL PARA RECEBER A OPÇÃO DIGITADA PELO USUÁRIO, E VARIAVAL DO CODIGO DE REMOCAO
    LISTA *li = criar();//CRIA UM PONTEIRO PARA LISTA, QUE RECEBE O ENDEREÇO DA LISTA RETORNADO PELA FUNÇÃO CRIAR();
    //O "TIPO" DO PONTEIRO SERÁ UMA ESTRUTURA: STRUCT LISTA.
    ALUNO a;//CRIA UMA ESTRUTURA DO "TIPO" STRUCT ALUNO.
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
            novoAluno(&a);//CHAMA A FUNÇÃO QUE LER OS CAMPOS DA ESTRUTURA ALUNO. (VEJA QUE SERÁ PASSADO O ENDEREÇO DA ESTRUTURA CRIADA)
            inserir(li,a);//CHAMA A FUNÇÃO QUE INSERE UM ELEMENTO NA LISTA. PARÂMENTROS: ENDEREÇO DA LISTA CRIADA E OS DADOS DE ALUNOS RECEM DIGITADOS
            break;
        case 5://OPÇÃO PARA REMOÇÃO DO PRIMEIRO ELEMENTO DA LISTA.
            mostrar(li);
            printf("DIGITE O CODIGO DO ALUNO QUE SERA REMOVIDO >> ");
            scanf("%d",&cod);
            remover(li,cod);//CHAMA A FUNÇÃO DE REMOÇAO. PARÂMETRO: ENDEREÇO DA LISTA CRIADA
            break;
        default:
            printf("OPCAO INVALIDA\n\n");
        }
    }
    liberar(li); //APÓS SAIR DO LAÇO, SERÁ CHAMADA A FUNÇÃO QUE DESALOCA O ESPAÇO DE MEMÓRIA PARA LISTA.
}
