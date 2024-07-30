#include <stdio.h>

int main(void){
    int n, count, count1;
    /*armazena a quantidade e porcentagem de mulheres que gostaram 
    do produto*/ 
    int mulheres = 0; 
    int porcentagemFem = 0;
    float porcentagemTotalFem = 0;

    /*armazena a quantidade e porcentagem de homens que gostaram 
    do produto*/
    int homens = 0;
    int porcentagemMasc = 0;
    float porcentagemTotalMasc = 0;

    /*leitura da quantidade de pessoas que serao entrevistadas*/
    printf("Informe a quantidade de pessoas que serao entrevistadas: ");
    scanf("%d", &n);

    //criação de matrizes para receber as respostas
    char sexo[n];
    char opiniao[n];

    for(count = 0; count < n; count++){
        printf("Informe o sexo (%d) [M/F]: ", count + 1);
        scanf(" %[^\n]", &sexo[count]);
        printf("Gostou do produto? [S/N] ");
        scanf(" %[^\n]", &opiniao[count]);
    }
    /*contador para quantidade e porcentagem de mulheres/homens 
    que gostaram ou nao do produto*/
    for(count1 = 0; count1 < n; count1++){
        if(sexo[count1] == 'F'){
            mulheres++;
            if(opiniao[count1] == 'S'){
                porcentagemFem++;
            }
        }
        if(sexo[count1] == 'M'){
            homens++;
            if(opiniao[count1] == 'N'){
                porcentagemMasc++;
            }
        }
    }

    //porcentagem feminina
    if(mulheres != 0){
        porcentagemTotalFem = (porcentagemFem * 100)/mulheres;
    }
    //porcentagem masculina
    if (homens != 0){
        porcentagemTotalMasc = (porcentagemMasc * 100)/homens;
    }

    printf("Pesquisa:\n");
    printf("%d pessoas foram entrevistadas, dentre elas:\n %d sao mulheres e %d sao homens\n", n, mulheres, homens);
    printf("%.2f%% de mulheres gostaram do produto\n", porcentagemTotalFem);
    printf("%.2f%% de homens nao gostaram do produto\n", porcentagemTotalMasc);
    return 0;    
}