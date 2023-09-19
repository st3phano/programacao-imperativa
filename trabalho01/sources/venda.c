#include "venda.h"
#include <stdio.h>
#include <stdlib.h>

Vetor_Vendas ler_arquivo_vendas(const char *caminho_arquivo_vendas)
{
   FILE *arquivo_vendas = fopen(caminho_arquivo_vendas, "r");
   if (arquivo_vendas == NULL)
   {
      printf("Falha ao abrir o arquivo '%s'\n", caminho_arquivo_vendas);
      exit(1);
   }

   int quantidade_vendas = -1;
   fscanf(arquivo_vendas, "%d", &quantidade_vendas);

   Venda *vendas = malloc(sizeof(*vendas) * quantidade_vendas);
   if (vendas == NULL)
   {
      printf("Falha ao alocar memória para '%s'\n", caminho_arquivo_vendas);
      fclose(arquivo_vendas);
      exit(1);
   }

   char string_formatacao[32];
   sprintf(string_formatacao, "%%hu %%hu %%hu");
   const int QUANTIDADE_ESPECIFICADORES_FORMATO = 3;
   for (int i = 0; i < quantidade_vendas; ++i)
   {
      int retorno_fscanf = fscanf(arquivo_vendas, string_formatacao,
                                  &(vendas[i].codigo_vendedor),
                                  &(vendas[i].codigo_produto),
                                  &(vendas[i].unidades));
      if (retorno_fscanf != QUANTIDADE_ESPECIFICADORES_FORMATO)
      {
         printf("Falha ao ler a linha %d do arquivo '%s'\n", i + 1, caminho_arquivo_vendas);
         fclose(arquivo_vendas);
         free(vendas);
         vendas = NULL;
         exit(1);
      }
   }
   fclose(arquivo_vendas);

   Vetor_Vendas vetor_vendas = {vendas, quantidade_vendas};
   return vetor_vendas;
}

void gravar_log_vendas(const Vetor_Vendas vetor_vendas, FILE *arquivo_gravar)
{
   const Venda *vendas = vetor_vendas.vendas;
   const int tamanho_vendas = vetor_vendas.tamanho_vendas;

   fputs("Log de Vendas:\n", arquivo_gravar);
   for (int i = 0; i < tamanho_vendas; ++i)
   {
      fprintf(arquivo_gravar, "[%d] %hu %hu %hu\n", i, vendas[i].codigo_vendedor, vendas[i].codigo_produto, vendas[i].unidades);
   }
}

void imprimir_log_vendas(const Vetor_Vendas vetor_vendas)
{
   const Venda *vendas = vetor_vendas.vendas;
   const int tamanho_vendas = vetor_vendas.tamanho_vendas;

   puts("Log de Vendas:");
   for (int i = 0; i < tamanho_vendas; ++i)
   {
      printf("[%d] %hu %hu %hu\n", i, vendas[i].codigo_vendedor, vendas[i].codigo_produto, vendas[i].unidades);
   }
}
