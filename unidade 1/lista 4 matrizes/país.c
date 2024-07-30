#include <stdio.h>

#define MAXIMO 1000

int main() {
    int i = 0;
    int L, C;
    char mapa[MAXIMO][MAXIMO];
    printf("Informe o tamanho do mapa: ");
    // le o tamanho do mapa
    scanf(" %d %d", &L, &C);
    // le o mapa
    for (i=0; i < L; i++) {
        scanf(" %[^\n]", mapa[i]);
    }
    int costa = 0;
    // percorre o mapa para encontrar os quadrados que sao parte da costa
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (mapa[i][j] == '#') {
                // vai verificar se o quadrado atual tem algum vizinho que é água ou está fora dos limites
                if (i == 0 || mapa[i-1][j] == '.' || i == L-1 || mapa[i+1][j] == '.' ||
                    j == 0 || mapa[i][j-1] == '.' || j == L-1 || mapa[i][j+1] == '.') {
                    costa++;
                }
            }
        }
    }
    printf("%d\n", costa);

    return 0;
}