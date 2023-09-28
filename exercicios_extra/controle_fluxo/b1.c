/**
 * Elabore um programa em C que leia dois valores inteiros: o primeiro define o limite
 * inferior de um intervalo, enquanto o segundo o limite superior. Imprima todos os
 * múltiplos de 3 no intervalo, incluindo os limites inferior e superior, se for o caso.
 * Testar as seguintes condições:
 * 1) O limite inferior não pode ser maior que o limite superior
 * 2) O limite inferior não pode ser igual ao limite superior.
 * O usuário deve ter até 3 chances para fornecer valores válidos para os limites
 * inferior e superior. Se o usuário ultrapassar esse número de chances, o programa
 * deve retornar o código 15 e encerrar.
 * IMPORTANTE: Os programas não podem conter o comando break, nem o
 * comando goto. Também, não podem conter um comando return dentro de um
 * bloco de repetição. Além disso, não podem usar array.
 */

#include <stdio.h>

int main(void)
{
   int limite_inferior = 0;
   int limite_superior = 0;
   int tentativa = 1;
   const int MAX_TENTATIVAS = 3;
   do
   {
      printf("%da tentativa\n", tentativa);
      printf("%s", "Digite o limite inferior: ");
      scanf("%d", &limite_inferior);
      printf("%s", "Digite o limite superior: ");
      scanf("%d", &limite_superior);
      ++tentativa;
   } while ((tentativa <= MAX_TENTATIVAS) && (limite_inferior >= limite_superior));

   if (tentativa > MAX_TENTATIVAS)
   {
      return 15;
   }

   const int DIVISOR = 3;
   while (limite_inferior % DIVISOR != 0 && limite_inferior <= limite_superior)
   {
      ++limite_inferior;
   }

   while (limite_inferior <= limite_superior)
   {
      printf("%d\n", limite_inferior);
      limite_inferior += DIVISOR;
   }

   return 0;
}
