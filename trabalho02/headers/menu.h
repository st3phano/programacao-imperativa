#ifndef MENU_H
#define MENU_H

#include "pessoa.h"

typedef enum
{
   ENCERRAR,
   INSERIR,
   REMOVER,
   EXIBIR,
   LISTAR,
   GRAVAR,
} OPCAO_MENU;

void exibir_menu(void);

/**
 * @param lista_ligada
 * Endereço do ponteiro para o início da lista
 * @returns
 * 'true' se a 'lista_ligada' foi alterada, 'false' caso contrário
 */
bool executar_opcao_menu_inserir(Pessoa **lista_ligada);

/**
 * @param lista_ligada
 * Endereço do ponteiro para o início da lista
 * @returns
 * 'true' se a 'lista_ligada' foi alterada, 'false' caso contrário
 */
bool executar_opcao_menu_remover(Pessoa **lista_ligada);

void executar_opcao_menu_exibir(Pessoa *inicio_lista_ligada);

void executar_opcao_menu_gravar(Pessoa *inicio_lista_ligada, const char *caminho_arquivo_gravar);

/**
 * @brief
 * Alocação na memória heap
 * @returns
 * 'NULL' em caso de falha
 */
Pessoa *ler_pessoa_da_entrada_padrao(void);

/**
 * @brief
 * Descarta espaço em branco inicial e
 * lê um inteiro de até 'max_digitos_inteiro' dígitos da entrada padrão,
 * repete até ser bem sucedido
 */
int ler_inteiro_da_entrada_padrao(const char *prompt, int max_digitos_inteiro);

/**
 * @brief
 * Descarta espaço em branco inicial,
 * lê uma string de até 'tamanho_buffer' - 1 caracteres da entrada padrão e armazena em 'buffer',
 * repete até ser bem sucedido
 */
void ler_string_da_entrada_padrao(const char *prompt, char *buffer, int tamanho_buffer);

void limpar_entrada_padrao(void);

#endif
