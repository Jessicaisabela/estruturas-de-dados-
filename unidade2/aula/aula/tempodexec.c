#include <stdio.h>
#include <time.h>

int main(){
    clock_t tempo_inicio = clock();
    //executar o algoritmo



    double final_tempo = (double) (clock() - tempo_inicio)/ CLOCKS_PER_SEC;
    printf("tempo de execucao: %f\n", final_tempo);
    return 0;
}