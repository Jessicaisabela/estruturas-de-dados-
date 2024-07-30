#include <stdio.h>

typedef struct curso{
    char nome[20];
    int cod;
}Curso;

typedef struct aluno{
    int mat, idade;
    char nome[20];
    Curso c;
}Aluno;

int main(void){
    Aluno a[3];
    for(int count = 0; count < 3; count++){
         printf("Digite o nome do aluno: \n");
         scanf("%[^\n]", &a[count].nome);
         getchar();
         printf("Digite o curso e a matricula: \n");
         scanf("%[^\n] %[^\n]", &a[count].c.nome, &a[count].c.cod);
    }

    return 0;
    }
