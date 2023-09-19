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
   imprimir_log_vendas(vetor_vendas);

   const char *CAMINHO_ARQUIVO_PRODUTOS = "produtos.txt";
   Vetor_Produtos vetor_produtos = ler_arquivo_produtos(CAMINHO_ARQUIVO_PRODUTOS);
   imprimir_catalogo_produtos(vetor_produtos);

   const char *CAMINHO_ARQUIVO_VENDEDORES = "vendedores.txt";
   Vetor_Vendedores vetor_vendedores = ler_arquivo_vendedores(CAMINHO_ARQUIVO_VENDEDORES);
   imprimir_lista_vendedores(vetor_vendedores);

   calcular_total_vendas_por_produto(vetor_produtos, vetor_vendas);
   imprimir_total_geral_vendas(calcular_total_geral_vendas(vetor_produtos));
   imprimir_total_vendas_por_produto(vetor_produtos);
   calcular_total_vendas_por_vendedor(vetor_vendedores, vetor_vendas, vetor_produtos);
   imprimir_total_vendas_por_vendedor(vetor_vendedores);

   free(vetor_vendas.vendas);
   vetor_vendas.vendas = NULL;
   free(vetor_produtos.produtos);
   vetor_produtos.produtos = NULL;
   free(vetor_vendedores.vendedores);
   vetor_vendedores.vendedores = NULL;

   return 0;
}
