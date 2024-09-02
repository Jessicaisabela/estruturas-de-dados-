#include <stdio.h>  
#include <stdlib.h> 
#include <string.h>



int main(void){

    char* nomes[4];
    char nome[21];
    char linha[100]; 

    FILE * arquivo_de_entrada;
    int i, n; 
    i=0; 

    arquivo_de_entrada = fopen("entrada_q1.txt", "rt"); 
    if (arquivo_de_entrada == NULL){ 
        printf("Não encontrado\n");
        exit(1); 
    }

    while(fgets(linha, 100, arquivo_de_entrada) !=NULL){ 

        sscanf(linha, "%20[^\n]", nome);
        n = strlen(nome);
        nomes[i] = (char*) malloc((n+1)*sizeof(char)); 
        strcpy(nomes[i], nome); 
        i++; 

    }

    fclose(arquivo_de_entrada);
    for(i=0; i<4; i++){ 
        printf(" %s \t", nomes[i]);
    }

    return 0;
}