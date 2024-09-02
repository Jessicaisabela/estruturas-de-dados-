#include<stdio.h>
#include<stdlib.h>

//função para abrir-criar arquivo e retornar este arquivo
FILE * open_file(char * nome, char * modo){
    FILE * arquivo = fopen(nome, modo);
    if(arquivo==NULL){
        printf("cant't open the file\n");
        exit(1);
    }
    else{
        printf("file open!\n");
    }
    return arquivo;
}
int main(void){
    FILE * arquivo_de_entrada, * arquivo_de_saida;
    arquivo_de_entrada = open_file("entrada_q3.txt", "r"); //ler o arquivo entrada
    arquivo_de_saida = open_file("saida_q3.txt", "w"); //cria o arquivo de saida
    char * nome_aluno[20];
    float nota1, nota2, nota3, media;
    //ler os dados dentro do arquivo fgets, fgetc, fscanf, sscanf
    while(!feof(arquivo_de_entrada)){ //enquanto não chegar ao final do arquivo
        fscanf(arquivo_de_entrada, "%s\t%f\t%f\t%f\t", nome_aluno, &nota1, &nota2, &nota3); //ler os dados do arquivo

        //calcular media
        media = (nota1+nota2+nota3)/3.0;
        //escreve no arquivo de saida
        if(media>=7){
            fprintf(arquivo_de_saida, "%s\t%.1f\tAprovado\n", nome_aluno, media);
        }
        else{
            fprintf(arquivo_de_saida, "%s\t%.1f\tReprovado\n", nome_aluno, media);
        }
    }
    fclose(arquivo_de_entrada);
    fclose(arquivo_de_saida);
}