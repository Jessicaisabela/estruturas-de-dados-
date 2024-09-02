#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

Produto criarProduto(int codigo, const char descricao[], int quantidade){
    Produto p;
    p.codigo = codigo;
    strncpy(p.descricao, descricao, sizeof(p.descricao) - 1);
    p.descricao[sizeof(p.descricao) - 1] = '\0';
    p.quantidade = quantidade;
    return p;
}

void adicionarProdutoAoEstoque(const char* nome_arquivo, Produto produto){
    FILE* arquivo = fopen(nome_arquivo, "ab");
    if (arquivo == NULL){
        perror("Não foi possível abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    fwrite(&produto, sizeof(Produto), 1, arquivo);
    fclose(arquivo);
}

void removerProdutoDoEstoque(const char* nome_arquivo, int codigo){
    FILE* arquivo = fopen(nome_arquivo, "r+b");
    if (arquivo == NULL){
        perror("Não foi possível abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE* temp = fopen("temp.bin", "wb");
    if (temp == NULL){
        perror("Não foi possível abrir o arquivo temporário");
        exit(EXIT_FAILURE);
    }

    Produto p;
    while (fread(&p, sizeof(Produto), 1, arquivo) == 1){
        if (p.codigo != codigo){
            fwrite(&p, sizeof(Produto), 1, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(nome_arquivo);
    rename("temp.bin", nome_arquivo);
}

void atualizarQuantidadeProduto(const char* nome_arquivo, int codigo, int nova_quantidade){
    FILE* arquivo = fopen(nome_arquivo, "r+b");
    if (arquivo == NULL){
        perror("Não foi possível abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    Produto p;
    while (fread(&p, sizeof(Produto), 1, arquivo) == 1){
        if (p.codigo == codigo){
            p.quantidade = nova_quantidade;
            fseek(arquivo, -sizeof(Produto), SEEK_CUR);
            fwrite(&p, sizeof(Produto), 1, arquivo);
            break;
        }
    }

    fclose(arquivo);
}

void exibirEstoque(const char* nome_arquivo){
    FILE* arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL){
        perror("Não foi possível abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    Produto p;
    while (fread(&p, sizeof(Produto), 1, arquivo) == 1){
        printf("Código: %d\nDescrição: %s\nQuantidade: %d\n\n", p.codigo, p.descricao, p.quantidade);
    }

    fclose(arquivo);
}