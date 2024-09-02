#include <stdio.h> //PARA USAR PRINTF E SCANF 
#include <stdlib.h> 
#include <string.h>
#include "ContaBancaria.h"
 
struct ContaBancaria{
    char titular[20]; //NOME
    float saldo; //SALDO DA CONTA
    int numero; //NUMERO CONTA
};

ContaBancaria * cria_conta(char * titular, float saldo, int numero){
    ContaBancaria * conta = (ContaBancaria*) malloc (sizeof(ContaBancaria));
    if(conta == NULL){
        printf("NO MEMORY!");
        exit(1);
    }else{
        printf("Conta alocada!\n");
    }
    //INICIALIZAR CONTA
    conta->numero = numero;
    conta->saldo = saldo;
    strcpy(conta-> titular, titular); //COPIA A STRING TITULAR PARA CONTA->TITULAR
    return conta;
    }
    
void deposita(ContaBancaria * conta, float dinheiro){
    conta->saldo += dinheiro;
    printf("Valor depositado com sucesso. \nNovo saldo: %f\n", conta->saldo);
}

void saca(ContaBancaria * conta, float valor){
    if(conta->saldo >= valor){
        conta->saldo -= valor;
        printf("Valor sacado com sucesso!");
    }else{
        printf("Valor insuficiente!\n");
    }
}

float saldo(ContaBancaria * conta){
    return conta->saldo;
    }

void exclui(ContaBancaria * conta){
    free(conta);
}