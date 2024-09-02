#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario Funcionario;

#define MAX 100

/*Função para alocar dinamicamente o funcionario*/
Funcionario ** alocaFuncionario();

/*Função para adicionar um funcionario*/
Funcionario ** adicionarFuncionario(Funcionario ** funcionarios, char * nome, int id, float salario, int * quant);

/*Função para remover o funcionario a partir do ID*/
Funcionario ** removerFuncionario(Funcionario ** funcionario, int id, int * quant);

/*Função para liberar o funcionario da memoria*/
void liberaFuncionario(Funcionario ** funcionarios, int quant);

/*Função para odentificar o funcionario a partir do ID*/
Funcionario * buscaFuncionario(Funcionario ** funcionarios, int id, int quant);

/*Função para listar os funcionarios*/
void listarFuncionarios(Funcionario ** funcionarios, int quant);