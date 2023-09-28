/**
 * Elabore um programa em C que calcule e imprima os n primeiros termos
 * da Sequência de Fibonacci, onde n é um valor inteiro positivo fornecido pelo
 * usuário. Muito embora a Sequência de Fibonacci seja, usualmente, definida de
 * forma recursiva, o programa deve calcular os n termos por meio de um algoritmo
 * iterativo, isto é, com uso de um comando de repetição. Mais especificamente, o
 * programa deve utilizar o comando for da linguagem C, sendo que cada iteração
 * do comando deve calcular e imprimir um termo da sequência. Não pode ser
 * usado o comando break, nem o comando continue.
 */

#include <stdio.h>

int main(void)
{
   int n = 0;
   printf("Digite o 'n' desejado: ");
   scanf("%d", &n);

   unsigned penultimo_termo = 0;
   unsigned ultimo_termo = 1;
   for (int termo = 1; termo <= n; ++termo)
   {
      printf("%do termo: %u\n", termo, penultimo_termo);
      unsigned aux = penultimo_termo;
      penultimo_termo = ultimo_termo;
      ultimo_termo += aux;
   }

   return 0;
}
