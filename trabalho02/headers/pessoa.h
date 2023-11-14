#ifndef PESSOA_H
#define PESSOA_H

#include <stdio.h>

#define TAMANHO_NOME_PESSOA 128
typedef struct Pessoa Pessoa;
struct Pessoa
{
   int id;
   char nome[TAMANHO_NOME_PESSOA];
   Pessoa *proxima;
};

/**
 * Constroi uma lista ligada ascendente em relação ao ID da 'Pessoa' no heap,
 * encerra a leitura do arquivo texto se encontrar uma linha mal formatada
 */
Pessoa *alocar_lista_ligada_pessoas_de_arquivo_texto(const char *caminho_arquivo_texto);

/**
 * Controi uma 'Pessoa' no heap a partir dos dados da próxima linha de um arquivo texto
 */
Pessoa *alocar_proxima_pessoa_de_arquivo_texto(FILE *arquivo_texto);

/**
 * Adiciona uma 'Pessoa' na lista ligada mantendo-a crescente em relação ao ID
 */
Pessoa *adicionar_pessoa_na_lista_ligada(Pessoa *lista, Pessoa *pessoa);

void gravar_lista_ligada_pessoas_no_arquivo_binario(Pessoa *lista, const char *caminho_arquivo_binario);

void desalocar_lista_ligada_pessoas(Pessoa *pessoas);

void imprimir_lista_ligada_pessoas(const Pessoa *lista);

#endif
