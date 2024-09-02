#include <stdio.h> // printf, scanf, fopen, fclose
#include <stdlib.h> // malloc, free
#include <string.h> // strcpy

typedef struct funcionario{
    char nome[21];
    char departamento;
    float salario;
    char funcional[11];
}Funcionario;

void copia_dados(FILE* fl, int n, Funcionario** pessoal); 
void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto); 
int main(void) {

    char linha[100]; 
    int n; 
    Funcionario** pessoal;
    FILE * arquivo_de_entrada; 
    int i;
    i=0; 

    arquivo_de_entrada = fopen("entrada_q2.txt", "rt"); 
    if (arquivo_de_entrada == NULL) { 
        printf("Não encontrado\n"); 
        exit(1); 
    }

    fgets(linha, 100, arquivo_de_entrada); 
    sscanf(linha, "%d", &n);
    printf("Numero de funcionarios: %d\n", n); 

    pessoal = (Funcionario**) malloc(n*sizeof(Funcionario*)); 
    for(i=0; i<n; i++){ 
        pessoal[i] = (Funcionario*) malloc(sizeof(Funcionario));
    }

    printf("\nCopiando dados do arquivo para o vetor...\n\n");
    copia_dados(arquivo_de_entrada, n, pessoal);
    printf("\nDados copiados com sucesso!\n\n");

    imprime_folha_pagamento(n, pessoal, 'A'); 
    imprime_folha_pagamento(n, pessoal, 'B'); 

    fclose(arquivo_de_entrada); 

    for(i=0; i<n; i++){
        free(pessoal[i]); 
    }
    free(pessoal); 

    return 0; 
}

void copia_dados(FILE* fl, int n, Funcionario** pessoal){
    int i=0; 
    while(!feof(fl)){
        if(i==0){
            fscanf(fl,"%d", &n); 
        }
        else{ 
            fscanf(fl,"%[^\t]\t%[^\t]\t%c\t%f ", pessoal[i-1]->funcional, pessoal[i-1]->nome, &pessoal[i-1]->departamento, &pessoal[i-1]->salario); 
        }
        i++; 
    }    
}

void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto){

    int i=0; 

    printf("\nFolha de pagamento do departamento %c\n", depto);  
    printf("Funcional\tNome\t\tDepartamento\tSalario\n"); 

    while(i<n){ 
        if(strcmp(&(pessoal[i]->departamento), &(depto)) == 0){ 
            printf("%s\t\t%s\t\t%c\t\t%.2f\n", pessoal[i]->funcional, pessoal[i]->nome, pessoal[i]->departamento, pessoal[i]->salario);
        }
        i++; 
    }
}