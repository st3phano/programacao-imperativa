#include "produto.h"
#include "total_vendas.h"
#include "venda.h"
#include "vendedor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
   const char *CAMINHO_ARQUIVO_VENDAS = "vendas.txt";
   Vetor_Vendas vetor_vendas = ler_arquivo_vendas(CAMINHO_ARQUIVO_VENDAS);

   const char *CAMINHO_ARQUIVO_PRODUTOS = "produtos.txt";
   Vetor_Produtos vetor_produtos = ler_arquivo_produtos(CAMINHO_ARQUIVO_PRODUTOS);

   const char *CAMINHO_ARQUIVO_VENDEDORES = "vendedores.txt";
   Vetor_Vendedores vetor_vendedores = ler_arquivo_vendedores(CAMINHO_ARQUIVO_VENDEDORES);

   double total_geral_vendas = calcular_total_vendas(vetor_vendas, vetor_produtos, vetor_vendedores);

   const char *CAMNHO_ARQUIVO_TOTAIS = "totais.txt";
   escrever_arquivo_totais(CAMNHO_ARQUIVO_TOTAIS, total_geral_vendas, vetor_produtos, vetor_vendas, vetor_vendedores);

   free(vetor_vendas.vendas);
   vetor_vendas.vendas = NULL;
   free(vetor_produtos.produtos);
   vetor_produtos.produtos = NULL;
   free(vetor_vendedores.vendedores);
   vetor_vendedores.vendedores = NULL;

   return 0;
}
