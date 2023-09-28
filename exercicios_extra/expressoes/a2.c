/**
 * Escreva um programa na Linguagem C que leia uma temperatura em graus
 * Celsius e apresente a temperatura convertida em graus Fahrenheit.
 */

#include <stdio.h>

int main(void)
{
   printf("%s", "Digite a temperatura em graus celsius: ");
   float temperatura_celsius = 0;
   scanf("%f", &temperatura_celsius);

   float temperatura_fahrenheit = (9 * temperatura_celsius + 160) / 5;
   printf("A temperatura em fahrenheit é %.2f\n", temperatura_fahrenheit);

   return 0;
}
