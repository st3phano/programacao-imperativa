/**
 * Elabore um programa em C para ler uma sequência de caráteres até que o
 * caráter 0 (zero) seja digitado. Enquanto os caráteres são lidos, o programa deverá
 * verificar se o caráter lido é uma vogal ou uma consoante e deverá acrescentar uma
 * unidade ao contador de vogais ou ao contador de consoantes, dependendo do que foi
 * lido. Ao final, o programa deverá imprimir o número de vogais e o número de
 * consoantes lidas.
 */

#include <stdio.h>

int main(void)
{
   int quantidade_vogais = 0;
   int quantidade_consoantes = 0;

   int c;
   do
   {
      c = getc(stdin);
      if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
      {
         switch (c)
         {
         case 'a':
         case 'A':
         case 'e':
         case 'E':
         case 'i':
         case 'I':
         case 'o':
         case 'O':
         case 'u':
         case 'U':
            ++quantidade_vogais;
            break;
         default:
            ++quantidade_consoantes;
            break;
         }
      }
   } while (c != '0');

   printf("Vogais: %d\n", quantidade_vogais);
   printf("Consoantes: %d\n", quantidade_consoantes);

   return 0;
}
