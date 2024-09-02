#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    char nome[50];
    int matricula;
    float media;
    };

Aluno * criarAluno(int matricula, char * nome, float media){
    Aluno * aluno = (Aluno *) malloc(sizeof(Aluno));
    aluno->matricula = matricula;
    strcpy(aluno->nome, nome);
    aluno->media = media;
    return aluno;
}

void salvarAlunoEmArquivo(char * nomeArquivo, Aluno * aluno){
    FILE * arq = fopen(nomeArquivo, "a");
    if(arq == NULL){
        printf("ERRO AO ABRIR ARQUIVO");
        return;
    }
    fprintf(arq, "%d\t%s\t%f\n", aluno->matricula, aluno->nome, aluno->media);
    fclose(arq);
}

void exibirAlunos(char * nomeArquivo){
    Aluno aluno;
    int cont= 1;
    FILE * arq = fopen(nomeArquivo, "r");
    if(arq == NULL){
        printf("ERRO AO ABRIR ARQUIVO");
        return;
    }
    while(fscanf(arq, "%d\t%[^\t]%f\n", &aluno.matricula, aluno.nome, &aluno.media) !=EOF)
    {
        printf("Aluno %d: %d\t%s\t%.2f\n", cont, aluno.matricula, aluno.nome, aluno.media);
        cont++;
    }
    fclose(arq);    
}