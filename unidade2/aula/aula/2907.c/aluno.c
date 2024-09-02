#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

struct aluno{
    char nome [20];
    int idade;
    long int matricula;
};

Aluno * alocaAluno(void){
    Aluno * aluno = (Aluno *) malloc(sizeof(Aluno));
    if(aluno == NULL){
        exit(1); 
    }
    else{
        printf("Aluno alocado!\n");
    }
    return aluno;
}

void preenche(Aluno * aluno){
    printf("Informe o nome:\t");
    scanf(" %[^\n]", aluno->nome);
    printf("Informe a idade e a matricula:\t");
    scanf("%d %ld", &aluno->idade, &aluno->matricula);
}

void imprime(Aluno * aluno){
    printf("=======================================\n");
    printf("Nome: %s\t Idade: %d\t Matricula: %ld", aluno->nome, aluno->idade, aluno->matricula);
}