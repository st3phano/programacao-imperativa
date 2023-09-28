/**
 * Escreva um programa na Linguagem C que efetue o cálculo do salário líquido
 * de um funcionário horista. Os dados fornecidos pelo usuário via teclado devem ser:
 * valor da hora aula, número de aulas dadas no mês e percentual de desconto do INSS e
 * o percentual de desconto do Imposto de Renda.
 */

#include <stdio.h>

int main(void)
{
   printf("%s", "Digite o valor da hora aula: ");
   double valor_hora_aula = 0;
   scanf("%lf", &valor_hora_aula);

   printf("%s", "Digite o número de aulas dadas no mês: ");
   unsigned aulas_dadas_mes = 0;
   scanf("%u", &aulas_dadas_mes);

   printf("%s", "Digite o percentual de desconto do INSS: ");
   double percentual_desconto_INSS = 0;
   scanf("%lf", &percentual_desconto_INSS);

   printf("%s", "Digite o percentual de desconto do imposto de renda: ");
   double percentual_desconto_imposto_renda = 0;
   scanf("%lf", &percentual_desconto_imposto_renda);

   double salario_bruto = valor_hora_aula * aulas_dadas_mes;
   double salario_com_desconto_INSS = salario_bruto - (salario_bruto * percentual_desconto_INSS / 100);
   double salario_liquido = salario_com_desconto_INSS - (salario_com_desconto_INSS * percentual_desconto_imposto_renda / 100);
   printf("Salário líquido: %.2f\n", salario_liquido);

   return 0;
}
