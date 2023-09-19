#include "produto.h"
#include <stdio.h>
#include <stdlib.h>

Vetor_Produtos ler_arquivo_produtos(const char *caminho_arquivo_produtos)
{
   FILE *arquivo_produtos = fopen(caminho_arquivo_produtos, "r");
   if (arquivo_produtos == NULL)
   {
      printf("Falha ao abrir o arquivo '%s'\n", caminho_arquivo_produtos);
      exit(1);
   }

   int quantidade_produtos = -1;
   fscanf(arquivo_produtos, "%d", &quantidade_produtos);

   Produto *produtos = malloc(sizeof(*produtos) * quantidade_produtos);
   if (produtos == NULL)
   {
      printf("Falha ao alocar memória para '%s'\n", caminho_arquivo_produtos);
      fclose(arquivo_produtos);
      exit(1);
   }

   char string_formatacao[32];
   sprintf(string_formatacao, "%%hu %%lf %%%d[^\r\n]", TAMANHO_DESCRICAO - 1);
   const int QUANTIDADE_ESPECIFICADORES_FORMATO = 3;
   for (int i = 0; i < quantidade_produtos; ++i)
   {
      int retorno_fscanf = fscanf(arquivo_produtos, string_formatacao,
                                  &(produtos[i].codigo),
                                  &(produtos[i].preco),
                                  produtos[i].descricao);
      if (retorno_fscanf != QUANTIDADE_ESPECIFICADORES_FORMATO)
      {
         printf("Falha ao ler a linha %d do arquivo '%s'\n", i + 1, caminho_arquivo_produtos);
         fclose(arquivo_produtos);
         free(produtos);
         produtos = NULL;
         exit(1);
      }

      int descarte = -1;
      do
      {
         descarte = fgetc(arquivo_produtos);
      } while (descarte != '\n' && descarte != EOF);

      produtos[i].total_vendas = 0;
   }
   fclose(arquivo_produtos);

   Vetor_Produtos vetor_produtos = {produtos, quantidade_produtos};
   return vetor_produtos;
}

void gravar_catalogo_produtos(const Vetor_Produtos vetor_produtos, FILE *arquivo_gravar)
{
   const Produto *produtos = vetor_produtos.produtos;
   const int tamanho_produtos = vetor_produtos.tamanho_produtos;

   fputs("Catálogo de Produtos:\n", arquivo_gravar);
   for (int i = 0; i < tamanho_produtos; ++i)
   {
      fprintf(arquivo_gravar, "[%d] %hu %.2f %s\n", i, produtos[i].codigo, produtos[i].preco, produtos[i].descricao);
   }
}

void imprimir_catalogo_produtos(const Vetor_Produtos vetor_produtos)
{
   const Produto *produtos = vetor_produtos.produtos;
   const int tamanho_produtos = vetor_produtos.tamanho_produtos;

   puts("Catálogo de Produtos:");
   for (int i = 0; i < tamanho_produtos; ++i)
   {
      printf("[%d] %hu %.2f %s\n", i, produtos[i].codigo, produtos[i].preco, produtos[i].descricao);
   }
}

double obter_preco_produto(const Vetor_Produtos vetor_produtos, const unsigned short codigo_produto)
{
   const Produto *produtos = vetor_produtos.produtos;
   const int quantidade_produtos = vetor_produtos.tamanho_produtos;
   for (int i = 0; i < quantidade_produtos; ++i)
   {
      if (codigo_produto == produtos[i].codigo)
      {
         return produtos[i].preco;
      }
   }

   return 0;
}
