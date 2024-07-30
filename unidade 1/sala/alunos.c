/*EXERCICIO:
1- Criar uma struct para manipular dados de um aluno.
Um aluno deve ter os campos: Nome, matricula, documentos
Os documentos devem ser representados por uma union. 
Os documentos são: CPF, RG, SUS, titulo eleitor, passaporte.
O programa deve receber os dados de N alunos, preencher e imprimir*/

#include <stdio.h>
#include <stdlib.h>

typedef union documentos{
    long int CPF, RG, SUS, titulo, passaporte;
}Documentos;

typedef struct alunos{
    char nome[20], matricula[10];
    int opcao_documento;
    Documentos doc;
}Alunos;

void preenche_aluno(Alunos *alunos){
    printf("Informe o nome do aluno(a):\t");
    scanf(" %[^\n]", alunos->nome);
    printf("Informe a matricula do aluno(a):\t");
    scanf(" %[^\n]", alunos->matricula);
    printf("\n===============================================================\n");
    printf("Escolha o documento e informe a opçao escolhida:\n1. CPF: \n2.RG: \n3.SUS: \n4.TITULO ELEITOR: \n5.PASSAPORTE: \t\n");
    printf("===============================================================\n");
    printf("Opcao: ");
    scanf("%ld", &alunos->opcao_documento);3
    printf("Digite o documento: ");
    switch(alunos->opcao_documento){
    case 1:
        scanf("%ld", &alunos->doc.CPF);
        break;
    case 2:
        scanf("%ld", &alunos->doc.RG);
        break;
    case 3:
        scanf("%ld", &alunos->doc.SUS);
        break;
    case 4:
        scanf("%ld", &alunos->doc.titulo);
        break;
    case 5:
        scanf("%ld", &alunos->doc.passaporte);
        break;
    default:
        printf("Opção invalida!");
        break;

    }
}

void imprime_aluno(Alunos *alunos){
    printf("===============================================================\n");
    switch(alunos->opcao_documento){
    case 1:
        printf("Nome:\t%s\nMatricula:\t%s\nCPF:\t%ld", alunos->nome, alunos->matricula, alunos->doc.CPF);
        break;
        getchar();
    case 2:
        printf("Nome:\t%s\nMatricula:\t%s\nRG:\t%ld", alunos->nome, alunos->matricula, alunos->doc.RG);
        break;
        getchar();
    case 3:
        printf("Nome:\t%s\nMatricula:\t%s\nSUS:\t%ld", alunos->nome, alunos->matricula, alunos->doc.SUS);
        break;
        getchar();
    case 4:
        printf("Nome:\t%s\nMatricula:\t%s\nTitulo de eleitor:\t%ld", alunos->nome, alunos->matricula, alunos->doc.titulo);
        break;
        getchar();
    case 5:
        printf("Nome:\t%s\nMatricula:\t%s\nPassaporte:\t%ld", alunos->nome, alunos->matricula, alunos->doc.passaporte);
        break;
        getchar();
    default:
        break;
    }
    printf("\n===============================================================");
}

int main(void){
    Alunos * alunos = (Alunos *)malloc(sizeof(Alunos));
    int quant_alunos;
    printf("Informe a quantidade de alunos: ");
    scanf("%d", &quant_alunos);
    for(int count = 0; count < quant_alunos; count++){
        printf("\nAluno(a) %d", count + 1);
        preenche_aluno(alunos);
    }
    printf("\n===============================================================");
    for(int count = 0; count < quant_alunos; count++){
        printf("Aluno(a) %d", count + 1);
        imprime_aluno(alunos);
    }
    return 0;
}