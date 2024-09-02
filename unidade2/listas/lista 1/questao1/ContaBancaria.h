
typedef struct ContaBancaria ContaBancaria;
/*Função que aloca memoria para struct conta e retorna seu endereço
Params:
    char * titular: nome do titular da conta
    float saldo: saldo disponivel na conta
    int numero: numero da conta*/
ContaBancaria * cria_conta(char * titular, float saldo, int numero);
/*Função que simula a operação de deposita
Params: 
    ContaBancaria * conta: representa conta bancaria
    float dinheiro: representa */
void deposita(ContaBancaria * conta, float dinheiro);
/*Função que simula a operação de sacar valor de uma conta 
Params:
    ContaBancaria * conta: representa conta bancaria
    float valor: valor que será decrementado da conta*/
void saca(ContaBancaria * conta, float valor);
/*Função que mostra o valor do saldo
Params: 
    ContaBancaria * conta: valor do saldo*/
float saldo(ContaBancaria * conta);

/*Função que exclui a conta, libera o espaço alocado dinamicamente para a estrutura*/