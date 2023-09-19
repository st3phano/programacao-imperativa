#ifndef VENDA_H
#define VENDA_H

typedef struct
{
   unsigned short codigo_vendedor;
   unsigned short codigo_produto;
   unsigned short unidades;
} Venda;

typedef struct
{
   Venda *vendas;
   int tamanho_vendas;
} Vetor_Vendas;

Vetor_Vendas ler_arquivo_vendas(const char *);
void imprimir_log_vendas(const Vetor_Vendas);

#endif
