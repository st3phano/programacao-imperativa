#include "vendedor.h"
#include <stdio.h>
#include <stdlib.h>

Vetor_Vendedores ler_arquivo_vendedores(const char *caminho_arquivo_vendedores)
{
   FILE *arquivo_vendedores = fopen(caminho_arquivo_vendedores, "r");
   if (arquivo_vendedores == NULL)
   {
      printf("Falha ao abrir o arquivo '%s'\n", caminho_arquivo_vendedores);
      exit(1);
   }

   int quantidade_vendedores = -1;
   fscanf(arquivo_vendedores, "%d", &quantidade_vendedores);

   Vendedor *vendedores = malloc(sizeof(*vendedores) * quantidade_vendedores);
   if (vendedores == NULL)
   {
      printf("Falha ao alocar memória para '%s'\n", caminho_arquivo_vendedores);
      fclose(arquivo_vendedores);
      exit(1);
   }

   char string_formatacao[32];
   sprintf(string_formatacao, "%%hu %%%d[^\r\n]", TAMANHO_NOME - 1);
   const int QUANTIDADE_ESPECIFICADORES_FORMATO = 2;
   for (int i = 0; i < quantidade_vendedores; ++i)
   {
      int retorno_fscanf = fscanf(arquivo_vendedores, string_formatacao,
                                  &(vendedores[i].codigo),
                                  vendedores[i].nome);
      if (retorno_fscanf != QUANTIDADE_ESPECIFICADORES_FORMATO)
      {
         printf("Falha ao ler a linha %d do arquivo '%s'\n", i + 1, caminho_arquivo_vendedores);
         fclose(arquivo_vendedores);
         free(vendedores);
         vendedores = NULL;
         exit(1);
      }

      int descarte = -1;
      do
      {
         descarte = fgetc(arquivo_vendedores);
      } while (descarte != '\n' && descarte != EOF);

      vendedores[i].total_vendas = 0;
   }
   fclose(arquivo_vendedores);

   Vetor_Vendedores vetor_vendedores = {vendedores, quantidade_vendedores};
   return vetor_vendedores;
}

void gravar_lista_vendedores(const Vetor_Vendedores vetor_vendedores, FILE *arquivo_gravar)
{
   const Vendedor *vendedores = vetor_vendedores.vendedores;
   const int tamanho_vendedores = vetor_vendedores.tamanho_vendedores;

   fputs("Lista de Vendedores:\n", arquivo_gravar);
   for (int i = 0; i < tamanho_vendedores; ++i)
   {
      fprintf(arquivo_gravar, "[%d] %hu %s\n", i, vendedores[i].codigo, vendedores[i].nome);
   }
}

void imprimir_lista_vendedores(const Vetor_Vendedores vetor_vendedores)
{
   const Vendedor *vendedores = vetor_vendedores.vendedores;
   const int tamanho_vendedores = vetor_vendedores.tamanho_vendedores;

   puts("Lista de Vendedores:");
   for (int i = 0; i < tamanho_vendedores; ++i)
   {
      printf("[%d] %hu %s\n", i, vendedores[i].codigo, vendedores[i].nome);
   }
}
