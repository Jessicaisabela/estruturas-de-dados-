#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int main(){
    const char* nome_arquivo = "estoque.bin";

    Produto produto1 = criarProduto(101, "Cadeira", 15);
    Produto produto2 = criarProduto(102, "Mesa", 8);

    adicionarProdutoAoEstoque(nome_arquivo, produto1);
    adicionarProdutoAoEstoque(nome_arquivo, produto2);
    printf("Estoque atual:\n");
    exibirEstoque(nome_arquivo);
    atualizarQuantidadeProduto(nome_arquivo, 101, 20);
    printf("Estoque após atualização:\n");
    exibirEstoque(nome_arquivo);
    removerProdutoDoEstoque(nome_arquivo, 102);
    printf("Estoque após remoção:\n");
    exibirEstoque(nome_arquivo);

    return 0;
}