#include "arquivo.h"
#include "pessoa.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

FILE *abrir_arquivo(const char *caminho_arquivo, const char *modo_fopen)
{
   FILE *arquivo = fopen(caminho_arquivo, modo_fopen);
   if (arquivo == NULL)
   {
      printf("Falha ao abrir o arquivo '%s'\n", caminho_arquivo);
   }

   return arquivo;
}

Pessoa *alocar_lista_ligada_pessoas_de_arquivo(const char *caminho_arquivo, const TIPO_ARQUIVO tipo_arquivo)
{
   FILE *arquivo = abrir_arquivo(caminho_arquivo,
                                 (tipo_arquivo == BINARIO) ? "rb" : "r");
   if (arquivo == NULL)
   {
      exit(EXIT_FAILURE);
   }

   Pessoa *inicio_lista = alocar_pessoa_de_arquivo(arquivo, tipo_arquivo);
   if (inicio_lista == NULL)
   {
      printf("Falha ao iniciar uma lista ligada de 'Pessoa's a partir do arquivo '%s'!\n", caminho_arquivo);
      fclose(arquivo);
      exit(EXIT_FAILURE);
   }

   Pessoa *proxima_pessoa;
   while ((proxima_pessoa = alocar_pessoa_de_arquivo(arquivo, tipo_arquivo)) != NULL)
   {
      if (!inserir_pessoa_na_lista_ligada(&inicio_lista, proxima_pessoa))
      {
         printf("Falha ao inserir '%s', id = %d na lista ligada!\n", proxima_pessoa->nome, proxima_pessoa->id);
      }
   }

   if (!feof(arquivo))
   {
      printf("O arquivo '%s' não foi lido completamente, verifique a formatação!\n", caminho_arquivo);
   }
   fclose(arquivo);

   return inicio_lista;
}

Pessoa *alocar_pessoa_de_arquivo(FILE *arquivo, const TIPO_ARQUIVO tipo_arquivo)
{
   Pessoa *pessoa = malloc(sizeof(*pessoa));
   if (pessoa == NULL)
   {
      puts("Falha ao alocar memória para 'Pessoa'!");
      return NULL;
   }

   if (tipo_arquivo == BINARIO)
   {
      const size_t QUANTIDADE_ELEMENTOS_FREAD = 1;
      size_t retorno_fread = fread(pessoa, sizeof(*pessoa), QUANTIDADE_ELEMENTOS_FREAD, arquivo);
      if (retorno_fread != QUANTIDADE_ELEMENTOS_FREAD)
      {
         free(pessoa);
         pessoa = NULL;
         return NULL;
      }
   }
   else // if (tipo_arquivo == TEXTO)
   {
      pessoa->id = ler_inteiro_de_arquivo_texto(arquivo, MAX_DIGITOS_ID_PESSOA);
      bool leu_inteiro = (pessoa->id != INT_MIN);
      if (!leu_inteiro)
      {
         free(pessoa);
         pessoa = NULL;
         return NULL;
      }

      bool leu_nome = ler_string_de_arquivo_texto(arquivo, pessoa->nome, TAMANHO_BUFFER_NOME_PESSOA);
      if (!leu_nome)
      {
         free(pessoa);
         pessoa = NULL;
         return NULL;
      }
   }

   pessoa->proxima = NULL;

   return pessoa;
}

int ler_inteiro_de_arquivo_texto(FILE *arquivo, int max_digitos_inteiro)
{
   int inteiro = INT_MIN;

   char formato_fscanf[32];
   sprintf(formato_fscanf, "%%%dd", max_digitos_inteiro);
   fscanf(arquivo, formato_fscanf, &inteiro);

   descartar_leitura_ate_espaco_em_branco(arquivo);

   return inteiro;
}

bool ler_string_de_arquivo_texto(FILE *arquivo, char *buffer, int tamanho_buffer)
{
   char formato_fscanf[32]; // ' ' no início descarta espaço em branco
   sprintf(formato_fscanf, " %%%d[^\r\n]", tamanho_buffer - 1);
   int retorno_fscanf = fscanf(arquivo, formato_fscanf, buffer);

   descartar_leitura_ate_espaco_em_branco(arquivo);

   return (retorno_fscanf == 1);
}

void descartar_leitura_ate_espaco_em_branco(FILE *arquivo)
{
   char ch;
   do
   {
      ch = fgetc(arquivo);
   } while (!isspace(ch) && ch != EOF);
}

bool converter_arquivo_tipo1_em_tipo2(const char *caminho_arquivo1, const TIPO_ARQUIVO tipo_arquivo1,
                                      const char *caminho_arquivo2, const TIPO_ARQUIVO tipo_arquivo2)
{
   Pessoa *inicio_lista = alocar_lista_ligada_pessoas_de_arquivo(caminho_arquivo1, tipo_arquivo1);
   // imprimir_lista_ligada_pessoas(inicio_lista);

   bool gravou = gravar_lista_ligada_pessoas_em_arquivo(inicio_lista, caminho_arquivo2, tipo_arquivo2);

   desalocar_lista_ligada_pessoas(inicio_lista);

   return gravou;
}

bool gravar_lista_ligada_pessoas_em_arquivo(Pessoa *inicio_lista, const char *caminho_arquivo, const TIPO_ARQUIVO tipo_arquivo)
{
   FILE *arquivo = abrir_arquivo(caminho_arquivo,
                                 (tipo_arquivo == BINARIO) ? "wb" : "w");
   if (arquivo == NULL)
   {
      desalocar_lista_ligada_pessoas(inicio_lista);
      exit(EXIT_FAILURE);
   }

   bool gravacao_bem_sucedida = true;
   if (tipo_arquivo == BINARIO)
   {
      const size_t QUANTIDADE_ELEMENTOS_FWRITE = 1;
      while (inicio_lista != NULL)
      {
         if (fwrite(inicio_lista, sizeof(*inicio_lista), QUANTIDADE_ELEMENTOS_FWRITE, arquivo) != QUANTIDADE_ELEMENTOS_FWRITE)
         {
            gravacao_bem_sucedida = false;
         }
         inicio_lista = inicio_lista->proxima;
      }
   }
   else
   {
      while (inicio_lista != NULL)
      {
         if (fprintf(arquivo, "%d %s\n", inicio_lista->id, inicio_lista->nome) < 0)
         {
            gravacao_bem_sucedida = false;
         }
         inicio_lista = inicio_lista->proxima;
      }
   }

   fclose(arquivo);
   return gravacao_bem_sucedida;
}
