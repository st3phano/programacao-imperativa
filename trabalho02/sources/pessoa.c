#include "pessoa.h"
#include "arquivo.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Pessoa *alocar_lista_ligada_pessoas_de_arquivo_texto(const char *caminho_arquivo_texto)
{
   FILE *arquivo_texto = abrir_arquivo(caminho_arquivo_texto, "r");
   if (arquivo_texto == NULL)
   {
      exit(EXIT_FAILURE);
   }

   Pessoa *lista = alocar_proxima_pessoa_de_arquivo_texto(arquivo_texto);
   if (lista == NULL)
   {
      printf("Falha ao iniciar uma lista ligada de 'Pessoa's a partir do arquivo '%s'!\n", caminho_arquivo_texto);
      fclose(arquivo_texto);
      exit(EXIT_FAILURE);
   }

   Pessoa *proxima_pessoa;
   while ((proxima_pessoa = alocar_proxima_pessoa_de_arquivo_texto(arquivo_texto)) != NULL)
   {
      lista = adicionar_pessoa_na_lista_ligada(lista, proxima_pessoa);
   }
   if (!feof(arquivo_texto))
   {
      printf("O arquivo '%s' não foi lido completamente, verifique a formatação!\n", caminho_arquivo_texto);
   }
   fclose(arquivo_texto);

   return lista;
}

Pessoa *alocar_proxima_pessoa_de_arquivo_texto(FILE *arquivo_texto)
{
   Pessoa *pessoa = malloc(sizeof(*pessoa));
   if (pessoa == NULL)
   {
      puts("Falha ao alocar memória para 'Pessoa'!");
      return NULL;
   }

   char formato_linha[32];
   sprintf(formato_linha, "%%d %%%d[^\r\n]", TAMANHO_NOME_PESSOA - 1);
   const int RETORNO_CORRETO_SCANF = 2;

   int retorno_scanf = fscanf(arquivo_texto, formato_linha, &(pessoa->id), pessoa->nome);
   if (retorno_scanf != RETORNO_CORRETO_SCANF)
   {
      free(pessoa);
      return NULL;
   }

   pessoa->proxima = NULL;

   return pessoa;
}

Pessoa *adicionar_pessoa_na_lista_ligada(Pessoa *lista, Pessoa *pessoa)
{
   if (lista == NULL || pessoa == NULL)
   {
      return lista;
   }

   // pessoa inserida no início da lista
   if (lista->id > pessoa->id)
   {
      pessoa->proxima = lista;
      return pessoa;
   }

   // procura a posição para inserir pessoa na lista
   Pessoa *penultimo = lista;
   Pessoa *ultimo = lista->proxima;
   while (ultimo != NULL && ultimo->id < pessoa->id)
   {
      penultimo = ultimo;
      ultimo = ultimo->proxima;
   }

   if (ultimo == NULL)
   {
      ultimo = pessoa;
   }
   else
   {
      penultimo->proxima = pessoa;
      pessoa->proxima = ultimo;
   }

   return lista;
}

void gravar_lista_ligada_pessoas_no_arquivo_binario(Pessoa *lista, const char *caminho_arquivo_binario)
{
   FILE *arquivo_binario = abrir_arquivo(caminho_arquivo_binario, "wb");
   if (arquivo_binario == NULL)
   {
      desalocar_lista_ligada_pessoas(lista);
      exit(EXIT_FAILURE);
   }

   while (lista != NULL)
   {
      fwrite(lista, sizeof(*lista), 1, arquivo_binario);
      lista = lista->proxima;
   }
   fclose(arquivo_binario);
}

void desalocar_lista_ligada_pessoas(Pessoa *pessoas)
{
   do
   {
      Pessoa *pessoa_seguinte = pessoas->proxima;
      free(pessoas);
      pessoas = pessoa_seguinte;
   } while (pessoas != NULL);
}

void imprimir_lista_ligada_pessoas(const Pessoa *lista)
{
   puts("Lista de pessoas:");
   while (lista != NULL)
   {
      printf("ID: %d Nome: %s\n", lista->id, lista->nome);
      lista = lista->proxima;
   }
}
