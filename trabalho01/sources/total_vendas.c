#include "total_vendas.h"
#include "produto.h"
#include "venda.h"
#include "vendedor.h"
#include <stdio.h>
#include <stdlib.h>

void escrever_arquivo_totais(const char *caminho_arquivo_totais, const double total_geral_vendas,
                             const Vetor_Produtos vetor_produtos, const Vetor_Vendas vetor_vendas, const Vetor_Vendedores vetor_vendedores)
{
   FILE *arquivo_totais = fopen(caminho_arquivo_totais, "w");
   if (arquivo_totais == NULL)
   {
      printf("Falha ao abrir o arquivo '%s'\n", caminho_arquivo_totais);
      free(vetor_vendas.vendas);
      free(vetor_produtos.produtos);
      free(vetor_vendedores.vendedores);
      exit(1);
   }

   gravar_log_vendas(vetor_vendas, arquivo_totais);
   gravar_catalogo_produtos(vetor_produtos, arquivo_totais);
   gravar_lista_vendedores(vetor_vendedores, arquivo_totais);
   gravar_total_geral_vendas(calcular_total_geral_vendas(vetor_produtos), arquivo_totais);
   gravar_total_vendas_por_produto(vetor_produtos, arquivo_totais);
   gravar_total_vendas_por_vendedor(vetor_vendedores, arquivo_totais);

   fclose(arquivo_totais);
}

void calcular_total_vendas_por_produto(Vetor_Produtos vetor_produtos, const Vetor_Vendas vetor_vendas)
{
   Produto *produtos = vetor_produtos.produtos;
   const int tamanho_produtos = vetor_produtos.tamanho_produtos;

   const Venda *vendas = vetor_vendas.vendas;
   const int tamanho_vendas = vetor_vendas.tamanho_vendas;

   for (int i_produtos = 0; i_produtos < tamanho_produtos; ++i_produtos)
   {
      produtos[i_produtos].total_vendas = 0;

      const unsigned short codigo_produto = produtos[i_produtos].codigo;
      const double preco_produto = produtos[i_produtos].preco;
      for (int i_vendas = 0; i_vendas < tamanho_vendas; ++i_vendas)
      {
         if (vendas[i_vendas].codigo_produto == codigo_produto)
         {
            produtos[i_produtos].total_vendas += preco_produto * vendas[i_vendas].unidades;
         }
      }
   }
}

void calcular_total_vendas_por_vendedor(Vetor_Vendedores vetor_vendedores, const Vetor_Vendas vetor_vendas, const Vetor_Produtos vetor_produtos)
{
   Vendedor *vendedores = vetor_vendedores.vendedores;
   const int tamanho_vendedores = vetor_vendedores.tamanho_vendedores;

   const Venda *vendas = vetor_vendas.vendas;
   const int tamanho_vendas = vetor_vendas.tamanho_vendas;

   for (int i_vendedores = 0; i_vendedores < tamanho_vendedores; ++i_vendedores)
   {
      vendedores[i_vendedores].total_vendas = 0;

      const unsigned short codigo_vendedor = vendedores[i_vendedores].codigo;
      for (int i_vendas = 0; i_vendas < tamanho_vendas; ++i_vendas)
      {
         if (codigo_vendedor == vendas[i_vendas].codigo_vendedor)
         {
            const double preco_produto = obter_preco_produto(vetor_produtos, vendas[i_vendas].codigo_produto);
            vendedores[i_vendedores].total_vendas += preco_produto * vendas[i_vendas].unidades;
         }
      }
   }
}

double calcular_total_geral_vendas(const Vetor_Produtos vetor_produtos)
{
   double total_geral_vendas = 0;

   const Produto *produtos = vetor_produtos.produtos;
   const int tamanho_produtos = vetor_produtos.tamanho_produtos;
   for (int i = 0; i < tamanho_produtos; ++i)
   {
      total_geral_vendas += produtos[i].total_vendas;
   }

   return total_geral_vendas;
}

void gravar_total_geral_vendas(const double total_geral_vendas, FILE *arquivo_gravar)
{
   fprintf(arquivo_gravar, "Total geral vendas: R$%.2f\n", total_geral_vendas);
}

void imprimir_total_geral_vendas(const double total_geral_vendas)
{
   printf("Total geral vendas: R$%.2f\n", total_geral_vendas);
}

void gravar_total_vendas_por_produto(const Vetor_Produtos vetor_produtos, FILE *arquivo_gravar)
{
   fputs("Total de vendas por produto:\n", arquivo_gravar);
   const Produto *produtos = vetor_produtos.produtos;
   const int tamanho_produtos = vetor_produtos.tamanho_produtos;
   for (int i = 0; i < tamanho_produtos; ++i)
   {
      fprintf(arquivo_gravar, "Produto %hu (%s): R$%.2f\n", produtos[i].codigo, produtos[i].descricao, produtos[i].total_vendas);
   }
}

void imprimir_total_vendas_por_produto(const Vetor_Produtos vetor_produtos)
{
   puts("Total de vendas por produto:");
   const Produto *produtos = vetor_produtos.produtos;
   const int tamanho_produtos = vetor_produtos.tamanho_produtos;
   for (int i = 0; i < tamanho_produtos; ++i)
   {
      printf("Produto %hu (%s): R$%.2f\n", produtos[i].codigo, produtos[i].descricao, produtos[i].total_vendas);
   }
}

void gravar_total_vendas_por_vendedor(const Vetor_Vendedores vetor_vendedores, FILE *arquivo_gravar)
{
   fputs("Total de vendas por vendedor:\n", arquivo_gravar);
   const Vendedor *vendedores = vetor_vendedores.vendedores;
   const int tamanho_vendedores = vetor_vendedores.tamanho_vendedores;
   for (int i = 0; i < tamanho_vendedores; ++i)
   {
      fprintf(arquivo_gravar, "Vendedor %hu (%s): R$%.2f\n", vendedores[i].codigo, vendedores[i].nome, vendedores[i].total_vendas);
   }
}

void imprimir_total_vendas_por_vendedor(const Vetor_Vendedores vetor_vendedores)
{
   puts("Total de vendas por vendedor:");
   const Vendedor *vendedores = vetor_vendedores.vendedores;
   const int tamanho_vendedores = vetor_vendedores.tamanho_vendedores;
   for (int i = 0; i < tamanho_vendedores; ++i)
   {
      printf("Vendedor %hu (%s): R$%.2f\n", vendedores[i].codigo, vendedores[i].nome, vendedores[i].total_vendas);
   }
}
