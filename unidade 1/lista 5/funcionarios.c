#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario{
    char nome[20];
    char cargo[20];
    float salario;
    int id; //guarda inteiros maiores
}Funcionario;

//FUNÇAO PARA PREENCHER DADOS
void preenche(Funcionario * servidor){
    printf("Informe o nome: \t");
    scanf(" %[^\n]", servidor->nome);
    getchar();
    printf("Informe o cargo: \t");
    scanf(" %[^\n]", servidor->cargo);
    printf("Informe o id: \t");
    scanf("%ld", &servidor->id);
    getchar();
    printf("Informe o salario: \t");
    scanf("%f", &servidor->salario);
 
}

//FUNÇAO PARA IMPRIMIR DADOS
void imprime(Funcionario * servidor, int quant){
    int i;
    for (i = 0; i < quant; i++){
        printf("-> Dados do %d funcionario: \n", i + 1);
        printf("NOME: %s\n", servidor[i].nome);
        printf("CARGO: %s\n", servidor[i].cargo);
        printf("ID: %d\n", servidor[i].id);
        printf("SALARIO: %.2f\n", servidor[i].salario);
        printf("=======================================\n");
     }
    
}

//FUNÇAO PARA ALTERAR O SALARIO
void alterar_salario(Funcionario * funcionario, int funAlterar){

    funAlterar -= 1; 
    printf("Digite o novo salario: ");
    scanf("%f", &funcionario[funAlterar].salario);
    printf("=======================================\n"); 
    printf("Novo salario do(a) %s: %.2f\n", funcionario[funAlterar].cargo, funcionario[funAlterar].salario);
}
//FUNÇAO P MAIOR E MENOR SALARIO 
void maiorMenorSalario(Funcionario * funcionario, int quant){
    int i, maior = 0, menor = 0;
    for(i = 0; i < quant; i++){
       if(funcionario[i].salario > funcionario[maior].salario){
        maior = i; 
       }
       if(funcionario[i].salario < funcionario[menor].salario){
        menor = i;
       }
    }
    printf("Cargo com maior salario: %s\t R$%.2f\n", funcionario[maior].cargo, funcionario[maior].salario);
    printf("Cargo com menor salario: %s\t R$%.2f", funcionario[menor].cargo, funcionario[menor].salario);
}


int main(void){
    int quantFunc, i, funAlterar;
    printf("Informe a quantidade de funcionarios: \n");
    scanf("%d", &quantFunc);
    Funcionario * funcionario = (Funcionario*) malloc(quantFunc * sizeof(Funcionario));
    if(funcionario == NULL){
        printf("ERRO\n");
        exit(1);
    }

    for (i = 0; i < quantFunc; i++){
        printf("\nPreencha dados do %d funcionario: \n", i + 1);
        preenche(&funcionario[i]);
        printf("=======================================\n");
    }
    imprime(funcionario, quantFunc);
    printf("De quem deseja alterar o salario? ");
    scanf(" %d", &funAlterar); 
    alterar_salario(funcionario, funAlterar);
    maiorMenorSalario(funcionario, quantFunc);
    free(funcionario);
    return 0;
} 