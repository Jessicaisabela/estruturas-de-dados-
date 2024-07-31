#include <stdio.h>
#include <math.h>

void calcula_hexagono (float 1,float * area, float*perimetro){
    *perimetro = 6*1;
    *area =(3* (pow (1,2) *sqrt (3)/2));
}

int main (void) {
    float area, perimetro,lado;
    float* pontArea, *pontPerimetro;
    pontArea= &area;
    pontPerimetro = &perimetro; 
    printf("Digite o lado do hexagono para ser calculado area e perimetro: ");
    scanf("%f", &lado);
    calcula_hexagono(lado, pontArea, pontPerimetro); 
    printf("O perimetro do hexano de lado %2.f e: %2.f \n", lado, perimetro);
    printf("A sua area e: %2.f", area);
    return 0;
}