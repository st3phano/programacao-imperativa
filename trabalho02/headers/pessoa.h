#ifndef PESSOA_H
#define PESSOA_H

#include <stdio.h>

#define TAMANHO_NOME_PESSOA 128
typedef struct Pessoa Pessoa;
struct Pessoa
{
   int id;
   char nome[TAMANHO_NOME_PESSOA];
   Pessoa *seguinte;
};

Pessoa *alocar_lista_pessoas_de_arquivo_texto(const char *caminho_arquivo_texto);
Pessoa *alocar_proxima_pessoa_de_arquivo_texto(FILE *arquivo_texto);
Pessoa *adicionar_pessoa_na_lista(Pessoa *lista, Pessoa *pessoa);
void gravar_lista_pessoas_no_arquivo_binario(Pessoa *lista, const char *caminho_arquivo_binario);
void desalocar_lista_pessoas(Pessoa *pessoas);
void imprimir_lista_pessoas(const Pessoa *lista);

#endif
