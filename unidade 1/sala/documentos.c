/*UNION:
    -São usadas quando queremos armazenar valores heterogeneos
em um mesmo espaço de memoria;
    -Os parametros compartilham o mesmo espaço de memória;
    -Só podemos armazenar um parâmetro por vez;*/
#include <stdio.h>
//EXEMPLO DE COMO USAR UNION:

typedef union documentos{
    char CPF[11]; //Formato 000.000.000-09
    char RG[11]; // APENAS NUMEROS INTEIROS 00000000000
}Documentos;

typedef struct pessoa{
    char nome[20];
    Documentos documento;
}Pessoa;

void preenche_pessoa(Pessoa * pessoa){
    /*Função para preencher struct pessoa*/
    int opcao_documento;
    printf("Informe o nome:\t");
    scanf(" %[^\n]", pessoa->nome);
    printf("Escolha e informe o documento 1- CPF ou 2- RG:\t");
    scanf("%d", &opcao_documento);
    switch(opcao_documento){
    case 1:
        scanf(" %[^\n]", pessoa->documento.CPF);
        break;
    case 2:
        scanf(" %[^\n]", pessoa->documento.RG);
        break;
    default:
        printf("Valor invalido\n");
        break;
    }
}

void imprime_pessoa(Pessoa *pessoa){
    /*Função para imprimir Pessoa*/
   printf("Nome: %s\nDocumento: %s\n", pessoa->nome, pessoa->documento.CPF);
    /*printf("Nome: %s\n Documento: %d\n", pessoa->nome, pessoa->documento.RG);*/
    
}

int main(void){
    Pessoa pessoa;
    preenche_pessoa(&pessoa);
    imprime_pessoa(&pessoa);
    return 0;

}