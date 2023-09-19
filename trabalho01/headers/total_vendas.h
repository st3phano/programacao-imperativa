#ifndef TOTAL_VENDAS_H
#define TOTAL_VENDAS_H

#include "produto.h"
#include "venda.h"
#include "vendedor.h"

void calcular_total_vendas_por_produto(Vetor_Produtos, const Vetor_Vendas);
void calcular_total_vendas_por_vendedor(Vetor_Vendedores vetor_vendedores, const Vetor_Vendas vetor_vendas, const Vetor_Produtos vetor_produtos);
double calcular_total_geral_vendas(const Vetor_Produtos);
void imprimir_total_geral_vendas(const double);
void imprimir_total_vendas_por_produto(const Vetor_Produtos);
void imprimir_total_vendas_por_vendedor(const Vetor_Vendedores vetor_vendedores);

#endif
