#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sPessoa
{
    char nome[20];
    float saque,deposito,pagamento;
}Pessoa;

typedef struct sNo{
    Pessoa dados;
    struct sNo*prox;
}NO;

typedef struct sFila{
    NO*inicio;
    NO*fim;
}Fila;

void inicializar(Fila *ptrF){
    ptrF->inicio=NULL;
    ptrF->fim=NULL;
}

int filavazia(Fila **ptrF){
    if((*ptrF)->inicio==NULL && (*ptrF)->fim==NULL){
        return 1;
    }else{
        return 0;
        }
}

NO* alocarNo(){
    return(NO*)malloc(sizeof(NO));
}

void desalocarNo(NO*aux){
    free(aux);
}

Pessoa Ler_Dados()
{
    Pessoa dados;
    printf("Digite o nome do cliente(a):\n");
    gets(dados.nome);
    printf("Digite a quantidade de deposito:\n");
    scanf("%f",&dados.deposito);
    printf("Digite a quantidade de saque:\n");
    scanf("%f",&dados.saque);
    printf("Digite a quantidade paga:\n");
    scanf("%f",&dados.pagamento);
    return dados;
}

void Imprime_Dados(Pessoa dados)
{
    printf("Nome do cliente(a):%s\n",dados.nome);
    printf("Quantidade de deposito:R$%0.2f\n",dados.deposito);
    printf("Quantidade de saque:R$%0.2f\n",dados.saque);
    printf("Quantidade paga:R$%0.2f\n",dados.pagamento);
    printf("\n");
}

void enfileirar(Fila *ptrF){
    NO* novo = alocarNo();

    if(novo!=NULL){
        novo->dados=Ler_Dados();
        novo->prox=NULL;
        if(filavazia(ptrF)==1){
            ptrF->inicio=novo;
            ptrF->fim=novo;
        }else{
                ptrF->fim->prox=novo;
                ptrF->fim=novo;
        }
    }else{
        printf("ERRO na alocacao do novo no");
    }
}

void impressao_naoclassica(Fila *ptrF)
{
    NO* aux = ptrF->inicio;
    if(filavazia(&ptrF))
    {
        printf("Fila vazia!\n");
    }
    else
    {
        while(aux!=NULL)
        {
            Imprime_Dados(aux->dados);
            aux=aux->prox;
        }
        printf("---Fim da Fila---\n");
    }

}

Menu()
{
        printf("1- Inserir um elemento na fila\n");
        printf("2- Exibir os elementos de forma nao classica\n");
        printf("3- Sair\n");
}




