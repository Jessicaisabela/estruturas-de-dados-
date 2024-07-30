#include <stdio.h>

union tipos{
    int inteiro;
    float real;
    char letra;
};
typedef union tipos Tipos;

int main(void){
    Tipos variavel;
    variavel.inteiro = 2;
    printf("%d, %f, %c\n", variavel.inteiro, variavel.real, variavel.letra);
    variavel.real = 2.5;
    printf("%d, %f, %c\n", variavel.inteiro, variavel.real, variavel.letra);
    variavel.letra = 's';
    printf("%d, %f, %c", variavel.inteiro, variavel.real, variavel.letra);
    return 0;
}