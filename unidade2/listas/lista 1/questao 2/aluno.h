#include "disciplina.h"

typedef struct aluno Aluno;

Aluno * cria_aluno(char nome[], int matricula);
void matricula_disciplina(Aluno* aluno, Disciplina * disciplina);
void exibe_aluno(Aluno * aluno);
void exclui_aluno(Aluno * aluno);