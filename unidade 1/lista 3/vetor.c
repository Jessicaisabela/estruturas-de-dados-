#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int tamanho, int* vetor){
    printf("Digite os elementos dos vetores");
    for(int count = 0; count < tamanho; count ++){
        scanf("%d ", &vetor[count]);
    }
}

void imprime_vetor(int tamanho, int* vetor){
    for(int count = tamanho - 1; count >= 0; count--){
        printf("%d\t", vetor[count]);
    }
}

int * aloca_vetor(int tamanho){
    int *vetor = (int*) malloc (tamanho * sizeof(int));
    if(vetor == NULL){
        printf("NO MEMORY");
        exit(1);
    }
    return vetor; 
}

int main(void){
    int tamanho;
    print("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);

    //ALOCA FUNÇÃO
    int * vetor = aloca_vetor(tamanho);
    
    //ELEMENTOS DO VETOR
    preenche_vetor(tamanho, vetor);

    //IMPRIME VETOR
    imprime_vetor(tamanho, vetor);
    free(vetor);
    return 0;
}