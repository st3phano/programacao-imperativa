#ifndef PESSOA_H
#define PESSOA_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_DIGITOS_ID_PESSOA 9
#define TAMANHO_BUFFER_NOME_PESSOA 64
typedef struct Pessoa Pessoa;
struct Pessoa
{
   int id;
   char nome[TAMANHO_BUFFER_NOME_PESSOA];
   Pessoa *proxima;
};

/**
 * @brief
 * Insere na primeira posição com 'id' maior que 'id' de pessoa
 * @param inicio_lista
 * Endereço do ponteiro para o início da lista
 * @returns
 * 'true' para inserção bem sucedida, 'false' para 'id' repetido
 */
bool inserir_pessoa_na_lista_ligada(Pessoa **inicio_lista, Pessoa *pessoa);

/**
 * @param inicio_lista
 * Endereço do ponteiro para o início da lista
 * @returns
 * 'true' para remoção bem sucedida, 'false' para 'id' não encontrado
 */
bool remover_pessoa_da_lista_ligada(Pessoa **inicio_lista, const int id_pessoa);

Pessoa *encontrar_pessoa_na_lista_ligada(Pessoa *inicio_lista, const int id_pessoa);

void desalocar_lista_ligada_pessoas(Pessoa *inicio_lista);

void imprimir_lista_ligada_pessoas(const Pessoa *inicio_lista);

void imprimir_pessoa(const Pessoa *pessoa);

#endif
