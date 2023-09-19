#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdio.h>

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

Vetor_Produtos ler_arquivo_produtos(const char *caminho_arquivo_produtos);
void gravar_catalogo_produtos(const Vetor_Produtos vetor_produtos, FILE *arquivo_gravar);
void imprimir_catalogo_produtos(const Vetor_Produtos vetor_produtos);
double obter_preco_produto(const Vetor_Produtos vetor_produtos, const unsigned short codigo_produto);

#endif
