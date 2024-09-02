#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    char nome[20];
    int idade;
    double nota1, nota2, nota3, media;
}Aluno;

Aluno * bubbleSort(Aluno * vetor, int tamanho){
    int i, j;
    Aluno aux;
    for (i = 0; i < tamanho; i++){
        for (j = 0; j < tamanho; j++){
            if(vetor[j].media > vetor[j + 1].media){
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }    
    }
    return vetor;
}

int main(void){
    int i = 0;
    int linhas = 0;
    char linha[200];

    FILE * arquivo = fopen("entrada.txt", "r");
    if(arquivo == NULL){
        print("ERRO!");
        exit(1);
    }
   
    while (fgets(linha, 200, arquivo) != NULL){
        linhas++;
    }
    printf("%d alunos\n", linhas);

    Aluno * alunos = (Aluno *) malloc (sizeof(Aluno) * linhas);
    if (alunos == NULL){
        printf("ERRO!\n");
        exit(1);
    }
    rewind(arquivo);
    while(fscanf(arquivo, "%(^,)\t%d,\t%f\t%f\t%f\n", alunos[i].nome, &alunos[i].idade, &alunos[i].nota1, &alunos[i].nota2, &alunos[i].nota3) != EOF){
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
    }
    
    alunos = bubbleSort(alunos, linhas);
    for(i = 0; i < linhas; i++){
        printf("Aluno %d: %s: %.1f\n", i + 1, alunos[i].nome, alunos[i].media);
    }
    fclose(arquivo);
    arquivo = fopen("resultados.txt", "w");
    for(i = 0; i < linhas; i++){
        fprintf("NOME: %s\tMEDIA: %.2f", alunos[i].nome, alunos[i].media);
    }
    fclose(arquivo);
}