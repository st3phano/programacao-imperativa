/**
 *  Escreva um programa na Linguagem C para calcular e apresentar o valor do
 * volume de uma lata de óleo cilíndrica utilizando a seguinte fórmula:
 * V = 3.14159 * R^2* h
 * sendo V é o volume, R é o raio e h é a altura da lata.
 */

#include <stdio.h>

int main(void)
{
   printf("%s", "Digite um valor para o raio da lata de óleo: ");
   double raio_lata = 0;
   scanf("%lf", &raio_lata);

   printf("%s", "Digite um valor para a altura da lata de óleo: ");
   double altura_lata = 0;
   scanf("%lf", &altura_lata);

   const double PI = 3.14159;
   double volume_lata = PI * (raio_lata * raio_lata) * altura_lata;
   printf("O volume da lata de óleo é %f\n", volume_lata);

   return 0;
}
