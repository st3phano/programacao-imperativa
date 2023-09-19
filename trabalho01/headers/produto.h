#ifndef PRODUTO_H
#define PRODUTO_H

#define TAMANHO_DESCRICAO 64
typedef struct
{
   unsigned short codigo;
   double preco;
   char descricao[TAMANHO_DESCRICAO];
   double total_vendas;
} Produto;

typedef struct
{
   Produto *produtos;
   int tamanho_produtos;
} Vetor_Produtos;

Vetor_Produtos ler_arquivo_produtos(const char *);
void imprimir_catalogo_produtos(const Vetor_Produtos);
double obter_preco_produto(const Vetor_Produtos, const unsigned short);

#endif
