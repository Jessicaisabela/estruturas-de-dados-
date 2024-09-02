#include<stdio.h>
#include<stdlib.h>

int main(void){
    //criando o arquivo aula01.txt
    FILE * arquivo;
    char texto_arquivo[100];
    arquivo = fopen("aula01.txt", "w");
    if(arquivo==NULL){
        printf("Can't creat file\n");
        exit(1);
    }
    else{
        printf("file created!\n");
    }
    //escrevendo no arquivo
    fprintf(arquivo, "hello world!");
    fclose(arquivo);
    //lendo os texto do arquivo
    arquivo = fopen("aula01.txt", "r");

    fsacnf(arquivo, "%[^\n]", texto_arquivo);
    printf("texto no arquivo: %s\n", texto_arquivo);
    fclose(arquivo);

    return 0;
}