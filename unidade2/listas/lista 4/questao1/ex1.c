#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 100000

int compare(const void *a, const void * b){
    return(*(int *) a - *(int*) b);
}

int buscaSequencial(int * entrada, int tamanho){
    /*FUnção que busca o maior elemento dentro de um vetor */
    int maior = entrada[0];
    /*Busca linear/sequencial*/
    for(int index = 0; index < tamanho; index++){
        if(maior < entrada[index]){ //Busca de maior elemento
        maior = entrada[index];
        }
    }
    return maior;

}

int buscaBinaria(int vet[], int maior, int tamanho){
    int inicio = 0, final = tamanho - 1;
    while(inicio <= final){
        int meio = inicio + (final - inicio) / 2;
        if(vet[meio] == maior){
            return vet[meio];
        }
        else if(vet[meio] < maior){
            inicio = meio + 1;
        }
        else{
            final = meio - 1;
        }
    }
    return -1;
}

int main(void){
    int entrada[TAMANHO];

    for(int index = 0; index < TAMANHO; index++){
        entrada[index]  = rand(); //Cria vetor com numeros aleatorios
    }
    clock_t tempo_inicial = clock();
    //Função de busca
    int maior = buscaSequencial(entrada, TAMANHO); //Complexidade O(n)
    double tempo_final = (double) (clock() - tempo_inicial) / CLOCKS_PER_SEC;
    tempo_final = tempo_final * 1000; // milisegundos
    printf("Maior elemento %d \nTempo de execução: %.4f (ms) \n", maior, tempo_final);

    qsort(entrada, TAMANHO, sizeof(int), compare);

    //Função de bysca O(n log n) ou O(log n)
    tempo_inicial = clock();
    int maior2 = buscaBinaria(entrada, maior, TAMANHO); //Complexidade O(log (n))

    tempo_final = (double) (clock() - tempo_inicial) / CLOCKS_PER_SEC;
    tempo_final = tempo_final * 1000; // milisegundos
    printf("Maior elemento %d \nTempo de execução: %.4f (ms) \n", maior2, tempo_final);
    return 0;

}