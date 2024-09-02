#include "funcionario.h"

int main(){
    Funcionario ** funcionarios = alocaFuncionario();
    int quant = 0, opcao, id;
    float salario;
    char nome[50];
    Funcionario * func;

    do{
        printf("MENU:\n");
        printf("1. ADICIONAR FUNCIONARIO;\n");
        printf("2. REMOVER FUNCIONARIO;\n");
        printf("3. BUSCAR FUNCIONARIO;\n");
        printf("4. LISTAR FUNCIONARIOS;\n");
        printf("5. SAIR\n");
        printf("->Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                printf("Informe o nome do funcionario: \n");
                scanf(" %[^\n]", nome);
                printf("Informe o id do funcionario: \n");
                scanf("%d", &id);
                printf("Informe o salario do funcionario: \n");
                scanf("%f", &salario);
                funcionarios = adicionarFuncionario(funcionarios, nome, id, salario, &quant);
                break;
            case 2:
                printf("Informe o ID do funcionario para ser removido: ");
                scanf("%d", &id);
                funcionarios = removerFuncionario(funcionarios, id, &quant);
                printf("Funcionario removido\n");
                break;
            case 3: 
                printf("Informe o ID para ser buscado: ");
                scanf("%d", &id);
                func = buscaFuncionario(funcionarios, id, quant);
                if(func != NULL){
                    printf("Funcionario encontrado!\n");
                } else{
                    printf("Funcionario não encontrado!\n");
                }
                break;
            case 4:
                listarFuncionarios(funcionarios, quant);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    liberaFuncionario(funcionarios, quant);
    return 0;
}