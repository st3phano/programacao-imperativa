#include "pessoa.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool inserir_pessoa_na_lista_ligada(Pessoa **inicio_lista, Pessoa *pessoa)
{
   if (inicio_lista == NULL || pessoa == NULL)
   {
      return false;
   }

   Pessoa *anterior = NULL;
   Pessoa *atual = *inicio_lista;

   bool fim_da_lista;
   bool id_repetido;
   bool encontrou_posicao;
   while (!(fim_da_lista = (atual == NULL)) &&
          !(id_repetido = (atual->id == pessoa->id)) &&
          !(encontrou_posicao = (atual->id > pessoa->id)))
   {
      anterior = atual;
      atual = atual->proxima;
   }

   if (id_repetido)
   {
      return false;
   }
   else // if (encontrou_posicao)
   {
      bool inserir_no_inicio = (anterior == NULL);
      if (inserir_no_inicio)
      {
         *inicio_lista = pessoa;
      }
      else
      {
         anterior->proxima = pessoa;
      }
      pessoa->proxima = atual;
   }

   return true;
}

bool remover_pessoa_da_lista_ligada(Pessoa **inicio_lista, const int id_pessoa)
{
   if (inicio_lista == NULL)
   {
      return false;
   }

   Pessoa *anterior = NULL;
   Pessoa *atual = *inicio_lista;

   bool fim_da_lista;
   bool encontrou_pessoa;
   while (!(fim_da_lista = (atual == NULL)) &&
          !(encontrou_pessoa = (atual->id == id_pessoa)))
   {
      anterior = atual;
      atual = atual->proxima;
   }

   if (fim_da_lista)
   {
      return false;
   }

   bool remover_do_inicio = (anterior == NULL);
   if (remover_do_inicio)
   {
      *inicio_lista = atual->proxima;
   }
   else
   {
      anterior->proxima = atual->proxima;
   }
   free(atual);
   atual = NULL;

   return true;
}

Pessoa *encontrar_pessoa_na_lista_ligada(Pessoa *inicio_lista, const int id_pessoa)
{
   Pessoa *pessoa = inicio_lista;

   while ((pessoa != NULL) &&
          (pessoa->id != id_pessoa))
   {
      pessoa = pessoa->proxima;
   }

   return pessoa;
}

void desalocar_lista_ligada_pessoas(Pessoa *inicio_lista)
{
   if (inicio_lista == NULL)
   {
      return;
   }
   desalocar_lista_ligada_pessoas(inicio_lista->proxima);
   free(inicio_lista);
   inicio_lista = NULL;
}

void imprimir_lista_ligada_pessoas(const Pessoa *inicio_lista)
{
   puts("- Lista ligada de pessoas:");
   while (inicio_lista != NULL)
   {
      imprimir_pessoa(inicio_lista);
      putchar('\n');
      inicio_lista = inicio_lista->proxima;
   }
}

void imprimir_pessoa(const Pessoa *pessoa)
{
   printf("ID: %*d   Nome: %s", MAX_DIGITOS_ID_PESSOA, pessoa->id, pessoa->nome);
}
