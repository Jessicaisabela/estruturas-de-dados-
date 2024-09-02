#include <stdio.h>
#include "ContaBancaria.h"

int main(void){
    ContaBancaria * conta = cria_conta("Maria", 1000.00, 202451);
    deposita(conta, 2500.00);
    saca(conta, 3000.00);
    float saldos = saldo(conta);
    free(conta);
    return 0; 
}