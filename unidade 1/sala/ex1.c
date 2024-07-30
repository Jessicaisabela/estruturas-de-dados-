#include <stdio.h>

typedef struct aluno{
   int mat, idade;
   char nome[20];
}Aluno;

void captura (struct aluno *a){
    printf("Digite a matricula e a idade:");
    scanf("%d %d", &a->mat, &a->idade);
    getchar();
    printf("Digite o nome do aluno: \n");
    scanf("%[^\n]", &a->nome);
    getchar();
    }

    void imprime (struct aluno *a){
        printf("Matricula: %d \n", a->mat);
        printf("Idade: %d \n", a->idade);
        printf("Nome: %s \n", a->nome);
    }

    int main(void){
        struct aluno a;
        captura(&a);
        imprime(&a);
        return 0;
    }