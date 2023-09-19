#ifndef VENDEDOR_H
#define VENDEDOR_H

#define TAMANHO_NOME 64
typedef struct
{
   unsigned short codigo;
   char nome[TAMANHO_NOME];
   double total_vendas;
} Vendedor;

typedef struct
{
   Vendedor *vendedores;
   int tamanho_vendedores;
} Vetor_Vendedores;

Vetor_Vendedores ler_arquivo_vendedores(const char *);
void imprimir_lista_vendedores(const Vetor_Vendedores);

#endif
