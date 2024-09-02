#include <stdio.h>
#include <time.h>

int main(){
    clock_t tempoInicio = clock();

    //EXECUTAR O ALGORITMO




    
    double finalTempo = (double)(clock() - tempoInicio)/
    CLOCKS_PER_SEC;
    printf("Tempo de execução: %f\n", finalTempo);
    return 0;
}