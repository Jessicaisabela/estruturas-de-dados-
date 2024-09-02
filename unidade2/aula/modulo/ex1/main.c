#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main(void){
    Aluno * aluno = alocaAluno(); //aloca
    preenche(aluno); //preenche
    imprime(aluno); //imprime
    free(aluno); //libera aluno
    return 0; 
}