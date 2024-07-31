#include <stdio.h>
#include <stdlib.h>

typedef enum meses
{
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
}Meses;

typedef struct data{
    int dia;
    Meses mes;
    int ano;
}Data;

void preencherData(Data *p){
    printf("Informe o dia:\n");
    scanf("%d", &p->dia);
    printf("Informe o mes:\n");
    scanf("%d",(int*) &(p->mes));
    printf("Informe o ano:\n");
    scanf("%d", &p->ano);
}

void imprimirData(Data *p){
    printf("%s%d/%s%d/%d", p->dia < 10 ? "0" : "", p->dia, p->mes < 10 ? "0" : "", p->mes, p->ano);
}

int main(void){
    Data data;
    preencherData(&data);
    imprimirData(&data);
    return 0;
}