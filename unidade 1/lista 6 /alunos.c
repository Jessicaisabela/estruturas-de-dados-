#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definindo cores no programa
#define reset   "\x1b[0m"
#define verde     "\x1b[31m"
#define amarelo  "\x1b[32m"
#define branco  "\x1b[33m"
#define cinza  "\x1b[34m"
#define rosa "\x1b[35m"
#define azul   "\x1b[36m"
#define vermelho   "\x1b[37m"

typedef struct aluno{
    int matricula;
    char nome[80];
    char turma[10];
    float notas[3];
    float media;
} Aluno;

void matricula(int n, Aluno **alunos);
void lanca_notas(int n, Aluno **alunos);
void imprime_tudo(int n, Aluno **alunos);
void imprime_turma(int n, Aluno **alunos, char *turma);
void imprime_turma_aprovados(int n, Aluno **alunos, char *turma);

int main(void){

    int num_vagas, i, opcao;
    char turmaSelecionada[20];
    printf(amarelo "Informe o numero de vagas:" reset);
    scanf("%d", &num_vagas);

    Aluno **alunos = (Aluno **)malloc(num_vagas * sizeof(Aluno *));
    for (i = 0; i < num_vagas; i++){
        alunos[i] = (Aluno *)malloc(sizeof(Aluno));
    }
    if (alunos == NULL){
        exit(1);
    }

    do{
        printf(azul"\n\t~~~~ MENU ~~~~\n");
        printf("[1]- Fazer matricula\n");
        printf("[2]- Vizualizar notas\n");
        printf("[3]- Vizualizar todos os dados\n");
        printf("[4]- Dados de uma turma\n");
        printf("[5]- Vizualizar aprovados\n");
        printf("Informe a opcao: " reset);
        scanf("%d", &opcao);
        system("cls");

        switch (opcao){
        case 1:
            matricula(num_vagas, alunos);
            break;
        case 2:
            lanca_notas(num_vagas, alunos);
            break;
        case 3:
            imprime_tudo(num_vagas, alunos);
            break;
        case 4:
            printf("Informe a turma:");
            scanf(" %[^\n]", turmaSelecionada);
            imprime_turma(num_vagas, alunos, turmaSelecionada);
            break;
        case 5:
            printf("Informe a turma:");
            scanf(" %[^\n]", turmaSelecionada);
            imprime_turma_aprovados(num_vagas, alunos, turmaSelecionada);
            break;
        default:
            printf("\nOpcao invalida!\n");
            break;
        }
        printf(vermelho"\nDeseja escolher outrar opcao?\n" reset);
        printf(amarelo "[1]-Sim\n" reset);
        printf(verde "[2]-Nao\n" reset);
        scanf("%d", &opcao);
    } while (opcao == 1);

    free(alunos);

    return 0;
}

void matricula(int n, Aluno **alunos){
    int i;
    for (i = 0; i < n; i++){
        printf(branco"\nInforme a matricula do aluno %d:", i);
        scanf("%d", &alunos[i]->matricula);
        printf("Informe o nome do aluno %d:", i);
        scanf(" %[^\n]", alunos[i]->nome);
        printf("Informe a turma do aluno %d:", i);
        scanf(" %[^\n]", alunos[i]->turma);
        printf("Informe a nota 1 do aluno %d:", i);
        scanf("%f", &alunos[i]->notas[0]);
        printf("Informe a nota 2 do aluno %d:", i);
        scanf("%f", &alunos[i]->notas[1]);
        printf("Informe a nota 3 do aluno %d:", i);
        scanf("%f" reset, &alunos[i]->notas[2]);
        alunos[i]->media = (alunos[i]->notas[0] + alunos[i]->notas[1] + alunos[i]->notas[2]) / 3;
    }
}

void lanca_notas(int n, Aluno **alunos){
    int i;
    printf("\n\t----Notas----\n");
    for (i = 0; i < n; i++){
        printf("\n\t---Aluno %d----\n", i);
        printf("Primeira unidade: %f\n", alunos[i]->notas[0]);
        printf("Segunda unidade: %f\n", alunos[i]->notas[1]);
        printf("Terceira unidade: %f\n", alunos[i]->notas[2]);
        printf("Media: %f", alunos[i]->media);
    }
}

void imprime_tudo(int n, Aluno **alunos){
    int i;
    printf("\n\t----Dados de todos os alunos----\n");
    for (i = 0; i < n; i++){
        printf("\n\t---Aluno %d---\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Matricula: %d\n", alunos[i]->matricula);
        printf("Turma: %s\n", alunos[i]->turma);
        printf("Notas:\n1: %f\n2: %f\n3: %f\n", alunos[i]->notas[0], alunos[i]->notas[1], alunos[i]->notas[2]);
        printf("Media: %f\n", alunos[i]->media);
    }
}

void imprime_turma(int n, Aluno **alunos, char *turma){
    int i;
    printf("\n\t----Dados dos alunos da turma %s----\n", turma);
    for (i = 0; i < n; i++){
        if (strcmp(alunos[i]->turma, turma) == 0){
            printf("\n\t---Aluno %d---\n", i);
            printf("Nome: %s\n", alunos[i]->nome);
            printf("Matricula: %d\n", alunos[i]->matricula);
            printf("Turma: %s\n", alunos[i]->turma);
            printf("Notas:\n1: %f\n2: %f\n3: %f\n", alunos[i]->notas[0], alunos[i]->notas[1], alunos[i]->notas[2]);
            printf("Media: %f\n", alunos[i]->media);
        }
    }
}

void imprime_turma_aprovados(int n, Aluno **alunos, char *turma){
    int i;
    printf("\n\t---- Aprovados Turma %s ----\n", turma);
    for (i = 0; i < n; i++){
        if (strcmp(alunos[i]->turma, turma) == 0){
            if (alunos[i]->media >= 7.0){
                printf("Nome: %s\n", alunos[i]->nome);
                printf("Matricula: %d\n", alunos[i]->matricula);
                printf("Turma: %s\n", alunos[i]->turma);
                printf("Notas:\n1: %f\n2: %f\n3: %f\n", alunos[i]->notas[0], alunos[i]->notas[1], alunos[i]->notas[2]);
                printf("Media: %f\n", alunos[i]->media);
            }else{
                printf("Nao ha aprovados na turma %s", turma);
            }
        }
    }
}