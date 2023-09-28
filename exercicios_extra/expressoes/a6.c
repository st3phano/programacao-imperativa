/**
 * Uma P.A. (progressão aritmética) é uma sequência de números reais na qual a
 * diferença entre dois números consecutivos quaisquer é constante, denominada a razão
 * da P.A. Como exemplos, temos as seguintes sequências como P.A.:
 * { 2, 5, 8, 11, 14, 17, 20 }
 * o primeiro termo da P.A. é 2 e a razão da P.A. é 3
 * { -4.5, -3.0, -1.5, 0, 1.5, 3.0, 4.5 }
 * o primeiro termo da P.A. é -4.5 e a razão é 1.5
 * { 10, 6, 2, -2, -6, -10 }
 * o primeiro termo da P.A. é 10 e a razão é -4
 * Escreva um programa na Linguagem C (contendo apenas a função main) que calcule
 * e imprima (na tela do computador) o n-ésimo termo de uma P.A., dados (via leitura
 * do teclado) o primeiro termo e a razão da P.A., além do próprio n. Por exemplo, se os
 * dados fornecidos para o programa forem:
 * • primeiro termo: 2
 * • razão: 3
 * • n: 4
 * o valor impresso pelo programa será 11.
 * IMPORTANTE: O programa não pode usar qualquer comando de repetição!
 */

#include <stdio.h>

int main(void)
{
   printf("%s", "Digite o primeiro termo da P.A.: ");
   double primeiro_termo_PA = 0;
   scanf("%lf", &primeiro_termo_PA);

   printf("%s", "Digite a razão da P.A.: ");
   double razao_PA = 0;
   scanf("%lf", &razao_PA);

   printf("%s", "Digite a posição do termo desejado: ");
   unsigned posicao_termo_desejado = 0;
   scanf("%u", &posicao_termo_desejado);

   double termo_desejado = primeiro_termo_PA + (razao_PA * (posicao_termo_desejado - 1));
   printf("%.2f", termo_desejado);

   return 0;
}
