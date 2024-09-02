#include <stdio.h>
#include "aluno.h"

int main(void){
    Aluno * aluno = criarAluno(123, "Maria", 8.5);
    salvarAlunoEmArquivo("aluno.txt", aluno);
    exibirAlunos("aluno.txt");
    return 0;
}