#include <stdio.h> 
#include <stdlib.h> 

int main(void){

    char linha[100]; 
    int v[10]; 
    FILE * arq, *arq1; 
    int n=0; 
    float media =0; 
    
    arq = fopen("entrada_q2.txt", "rt");
    if (arq == NULL) {
        printf("Não encontrado\n");
        exit(1);
    }

    arq1 = fopen("saida_q2.txt", "wt");
    if (arq1 == NULL) {
        printf("ERRO\n");
        exit(1);
    }

    while (fgets(linha,100,arq) != NULL){
        sscanf(linha, "%d ", &v[n]);
        media+=v[n];
        n++;
    }

    int menor = v[0];
    int maior = v[0]; 

    for(n=0; n<10; n++){
            if(v[n] < menor)
                menor =  v[n];
            if(v[n] > maior)
                maior =  v[n];
        }
    fprintf(arq1, "  menor elemento: %d\n maior elemento: %d \n media dos elementos %f ", menor, maior, media/10);
    fclose(arq);
    return 0;
}