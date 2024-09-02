#include <stdio.h>

typedef struct aluno Aluno;
/*Função que recebe os dados dos alunos 
 Params: 
    int matricula: matricula do aluno
    char * nome: nome do aluno
    float media: media do aluno*/
Aluno * criarAluno(int matricula, char * nome, float media);

/*Função 
 Params: 
    char * nomeArquivo:
    Aluno aluno: */
void salvarAlunoEmArquivo(char * nomeArquivo, Aluno * aluno);



/*Função para exibir os dados dos alunos
 Params: 
    char * nomeArquivo: para abrir o arquivo */
void exibirAlunos(char * nomeArquivo);