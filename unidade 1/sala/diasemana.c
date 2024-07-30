#include <stdio.h>

typedef enum dias_semana{
    SEGUNDA = 2,
    TERCA,
    QUARTA,
    QUINTA, 
    SEXTA,
    SABADO,
    DOMINGO
}DiaSemana;

int main(void){
    DiaSemana dia;
    printf("Informe o dia da semana: 2-8\t");
    scanf("%d", &dia);
    switch(dia){
        case SEGUNDA:
            printf(" Segunda-feira\n");
            break;
        case TERCA:
            printf(" Terça-feira\n");
            break;
        case QUARTA:
            printf(" Quarta-feira\n");
            break;
        case QUINTA:
            printf(" Quinta-feira\n");
            break;
        case SEXTA:
            printf(" Sexta-feira\n");
            break;
        case SABADO:
            printf(" Sabado\n");
            break;
        case DOMINGO:
            printf(" Domingo\n");
            break;
        default:
        printf("Dia não cadastrado\n");
        break;
    }
        dia = SEGUNDA;
    printf("Dia da semana: %d\n", dia);
    return 0;
}
