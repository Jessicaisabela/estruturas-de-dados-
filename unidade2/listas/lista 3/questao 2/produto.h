#define PRODUTO_H

typedef struct {
    int codigo;
    char descricao[100];
    int quantidade;
} Produto;

Produto criarProduto(int codigo, const char descricao[], int quantidade);
void adicionarProdutoAoEstoque(const char* nome_arquivo, Produto produto);
void removerProdutoDoEstoque(const char* nome_arquivo, int codigo);
void atualizarQuantidadeProduto(const char* nome_arquivo, int codigo, int nova_quantidade);
void exibirEstoque(const char* nome_arquivo);