#include <stdio.h>
#include <stdlib.h>

typedef enum produto{
    ALIMENTO,
    BEBIDA,
    ELETRONICO
}TipoProduto;

typedef union tipo{
    char alimento[50];
    char bebida[50];
    char eletronico[50];
}Tipo;

typedef struct produtoo{
    char nome[50];
    float preco;
    Tipo tipo;
    TipoProduto tipoProduto;
}Produto;

void lerProduto(Produto *p){
    printf("Informe o nome do produto:\n");
    scanf(" %[^\n]", p->nome);
    printf("Informe o preco do produto:\n");
    scanf("%f", &(p->preco));
    printf("Informe o tipo (0 para alimento, 1 para bebida, 2 para eletronico):\n");
    scanf("%d", (int *)&(p->tipoProduto));
    switch (p->tipoProduto){
    case ALIMENTO:
        printf("Informe o nome do alimento:\n");
        scanf(" %[^\n]", p->tipo.alimento);
        break;
    case BEBIDA:
        printf("Informe o nome da bebida:\n");
        scanf(" %[^\n]", p->tipo.bebida);
        break;
    case ELETRONICO:
        printf("Informe o nome do eletronico:\n");
        scanf(" %[^\n]", p->tipo.eletronico);
        break;
    }
}

void imprimirProduto(Produto *p){
    printf("\n-------------------------------\n");
    printf("Nome: %s\n", p->nome);
    printf("Preco: %.2f\n", p->preco);
    switch (p->tipoProduto)
    {
    case ALIMENTO:
        printf("Tipo: Alimento - %s\n", p->tipo.alimento);
        break;
    case BEBIDA:
        printf("Tipo: Bebida - %s\n", p->tipo.bebida);
        break;
    case ELETRONICO:
        printf("Tipo: Eletronico - %s\n", p->tipo.eletronico);
        break;
    }
    printf("\n-------------------------------\n");
}

int main()
{
    Produto *produto = (Produto *)malloc(sizeof(Produto));
    if(produto == NULL){
        exit(1);
    }
    lerProduto(produto);
    imprimirProduto(produto);
    free(produto);
    return 0;
}