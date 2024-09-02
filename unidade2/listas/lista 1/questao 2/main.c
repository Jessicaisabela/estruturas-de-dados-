#include <stdio.h>
#include "aluno.h"
#include "disciplina.h"

int main(){
    Disciplina * geometria = cria_disciplina("Geometria", 101);
    Disciplina * historia = cria_disciplina("Historia", 102);
    Disciplina * calculo = cria_disciplina("Calculo ", 103);
    Aluno * aluno1 = cria_aluno("Laura", 12345);
    Aluno * aluno2 = cria_aluno("Ana", 67890);

    matricula_disciplina(aluno1, geometria);
    matricula_disciplina(aluno1, historia);
    matricula_disciplina(aluno2, calculo);
    matricula_disciplina(aluno2, geometria);
    exibe_aluno(aluno1);
    exibe_aluno(aluno2);
    exclui_aluno(aluno1);
    exclui_aluno(aluno2);
    exclui_disciplina(geometria);
    exclui_disciplina(historia);
    exclui_disciplina(calculo);

    return 0;
}