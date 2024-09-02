#include "funcionario.h"

struct funcionario{
    char nome[50];
    int id;
    float salario;
};

Funcionario ** alocaFuncionario(){
    Funcionario ** novo = (Funcionario **) malloc (sizeof (Funcionario*) * MAX);
    if(novo == NULL){
        printf("ERRO!");
        exit(1);
    }
    return novo;
}

Funcionario ** adicionarFuncionario(Funcionario ** funcionarios, char * nome, int id, float salario, int * quant){
    funcionarios[(*quant)] = (Funcionario *) malloc(sizeof(Funcionario));
    if (funcionarios[(*quant)] == NULL){
        printf("ERRO!");
        exit(1);
    }
    funcionarios[(*quant)]->id = id;
    funcionarios[(*quant)]->salario = salario;
    strcpy(funcionarios[(*quant)]->nome, nome);
    (*quant)++;
    return funcionarios;
}

Funcionario ** removerFuncionario(Funcionario ** funcionario, int id, int * quant){
    int i; 
    for(i = 0; i <(*quant); i++){
        if(funcionario[i]->id == id){
            break;
        }
    }
    free(funcionario[i]);
    for(int j = i; j < (*quant); j++){
        funcionario[j] = funcionario[j + 1];
    }
    funcionario[(*quant)] == NULL;
    (*quant)--;
    return funcionario;
}
    
void liberaFuncionario(Funcionario ** funcionarios, int quant){
    for(int i = 0; i < quant; i++){
        free(funcionarios[i]);
    }
    free(funcionarios);
}

Funcionario * buscaFuncionario(Funcionario ** funcionarios, int id, int quant){
    for(int i = 0; i < quant; i++){
        if(funcionarios[i]->id == id){
            return funcionarios[i];
        }
    }
    return NULL;
}

void listarFuncionarios(Funcionario ** funcionarios, int quant){
    for(int i = 0; i < quant; i++){
        printf("====================================================");
        printf("NOME: %s\nID: %d\nSALARIO: %.2f\n", funcionarios[i]->nome, funcionarios[i]->id, funcionarios[i]->salario);
    }
}