#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"

struct disciplina{
    char nome[100];
    int codigo;
};

Disciplina* cria_disciplina(char nome[], int codigo){
    Disciplina* nova_disciplina = (Disciplina*)malloc(sizeof(Disciplina));
    if (nova_disciplina == NULL) {
        printf("Erro ao alocar memória para a disciplina.\n");
        exit(1);
    }
    strcpy(nova_disciplina->nome, nome);
    nova_disciplina->codigo = codigo;
    return nova_disciplina;
}

void exclui_disciplina(Disciplina * disciplina){
    free(disciplina);
}

void exibe_disciplina(Disciplina* disciplina){
    printf("Disciplina: %s | Código: %d\n", disciplina->nome, disciplina->codigo);
}