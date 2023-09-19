#include "total_vendas.h"
#include "produto.h"
#include "venda.h"
#include "vendedor.h"
#include <stdio.h>

void calcular_total_vendas_por_produto(Vetor_Produtos vetor_produtos, const Vetor_Vendas vetor_vendas)
{
   Produto *produtos = vetor_produtos.produtos;
   const int quantidade_produtos = vetor_produtos.tamanho_produtos;

   const Venda *vendas = vetor_vendas.vendas;
   const int quantidade_vendas = vetor_vendas.tamanho_vendas;

   for (int i_produtos = 0; i_produtos < quantidade_produtos; ++i_produtos)
   {
      produtos[i_produtos].total_vendas = 0;

      const unsigned short codigo_produto = produtos[i_produtos].codigo;
      const double preco_produto = produtos[i_produtos].preco;
      for (int i_vendas = 0; i_vendas < quantidade_vendas; ++i_vendas)
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
   const int quantidade_vendedores = vetor_vendedores.tamanho_vendedores;

   const Venda *vendas = vetor_vendas.vendas;
   const int quantidade_vendas = vetor_vendas.tamanho_vendas;

   for (int i_vendedores = 0; i_vendedores < quantidade_vendedores; ++i_vendedores)
   {
      vendedores[i_vendedores].total_vendas = 0;

      const unsigned short codigo_vendedor = vendedores[i_vendedores].codigo;
      for (int i_vendas = 0; i_vendas < quantidade_vendas; ++i_vendas)
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
   const int quantidade_produtos = vetor_produtos.tamanho_produtos;
   for (int i = 0; i < quantidade_produtos; ++i)
   {
      total_geral_vendas += produtos[i].total_vendas;
   }

   return total_geral_vendas;
}

void imprimir_total_geral_vendas(const double total_geral_vendas)
{
   printf("Total geral vendas: %.2f\n", total_geral_vendas);
}

void imprimir_total_vendas_por_produto(const Vetor_Produtos vetor_produtos)
{
   puts("Total de vendas por produto:");
   const Produto *produtos = vetor_produtos.produtos;
   const int quantidade_produtos = vetor_produtos.tamanho_produtos;
   for (int i = 0; i < quantidade_produtos; ++i)
   {
      printf("Produto %hu (%s): R$%.2f\n", produtos[i].codigo, produtos[i].descricao, produtos[i].total_vendas);
   }
}

void imprimir_total_vendas_por_vendedor(const Vetor_Vendedores vetor_vendedores)
{
   puts("Total de vendas por vendedor:");
   const Vendedor *vendedores = vetor_vendedores.vendedores;
   const int quantidade_vendedores = vetor_vendedores.tamanho_vendedores;
   for (int i = 0; i < quantidade_vendedores; ++i)
   {
      printf("Vendedor %hu (%s): R$%.2f\n", vendedores[i].codigo, vendedores[i].nome, vendedores[i].total_vendas);
   }
}