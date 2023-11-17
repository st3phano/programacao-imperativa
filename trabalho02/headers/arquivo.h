#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "pessoa.h"
#include <stdio.h>

typedef enum
{
   BINARIO,
   TEXTO
} TIPO_ARQUIVO;

FILE *abrir_arquivo(const char *caminho_arquivo, const char *modo_fopen);

/**
 * @brief
 * Constroi na memória heap, ordem ascendente conforme o 'id',
 * encerra a leitura do arquivo se encontrar algo inesperado
 */
Pessoa *alocar_lista_ligada_pessoas_de_arquivo(const char *caminho_arquivo, const TIPO_ARQUIVO tipo_arquivo);

/**
 * @brief
 * Constroi na memória heap a partir da posição atual do ponteiro de arquivo
 */
Pessoa *alocar_pessoa_de_arquivo(FILE *arquivo, const TIPO_ARQUIVO tipo_arquivo);

/**
 * @brief
 * Lê um inteiro de até 'max_digitos_inteiro' dígitos do 'arquivo'
 * @returns
 * O inteiro lido em caso de sucesso, INT_MIN se falhar
 */
int ler_inteiro_de_arquivo_texto(FILE *arquivo, int max_digitos_inteiro);

/**
 * @brief
 * Descarta espaço em branco inicial,
 * lê uma string de até 'tamanho_buffer' - 1 caracteres do 'arquivo' e armazena em 'buffer'
 * @returns
 * 'true' se bem sucedido, 'false' caso contrário
 */
bool ler_string_de_arquivo_texto(FILE *arquivo, char *buffer, int tamanho_buffer);

void descartar_leitura_ate_espaco_em_branco(FILE *arquivo);

/**
 * @returns
 * 'true' se bem sucedido, 'false' se corrompeu o 'arquivo2'
 */
bool converter_arquivo_tipo1_em_tipo2(const char *caminho_arquivo1, const TIPO_ARQUIVO tipo_arquivo1,
                                      const char *caminho_arquivo2, const TIPO_ARQUIVO tipo_arquivo2);

bool gravar_lista_ligada_pessoas_em_arquivo(Pessoa *inicio_lista, const char *caminho_arquivo, const TIPO_ARQUIVO tipo_arquivo);

#endif
