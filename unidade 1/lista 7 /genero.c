#include <stdio.h>

typedef enum genero{
    MASCULINO = 1,
    FEMININO
}Genero;

typedef struct pessoa{
    char nome[10];
    Genero genero;
    int idade;
}Pessoa;

void preenche_pessoa(Pessoa *pessoa){
    printf("Informe o nome: ");
    scanf(" %[^\n]", pessoa->nome);
    printf("Informe a idade: ");
    scanf("%d", pessoa->idade);
    printf("Informe o genero: ");
    scanf(" %d", pessoa->genero);
}

void imprime_pessoa(Pessoa *pessoa){
    printf("NOME: %s", &pessoa->nome);
    printf("IDADE: %d", pessoa->idade);
    printf("GENERO: %d", pessoa->genero);
}

int main(void){
    Pessoa pessoa;
    preenche_pessoa(&pessoa);
    imprime_pessoa(&pessoa);
    return 0;

}