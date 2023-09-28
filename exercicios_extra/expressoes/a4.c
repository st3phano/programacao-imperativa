/**
 * Escreva um programa na Linguagem C que leia um valor de hora no formato
 * hora:minutos e informe (calcule) o total de minutos que se passaram desde o
 * início do dia (0:00h).
 */

#include <stdio.h>

int main(void)
{
   printf("%s", "Digite um valor de hora no formato - horas:minutos -: ");
   int horas = 0;
   int minutos = 0;
   scanf("%d : %d", &horas, &minutos);

   const int MINUTOS_POR_HORA = 60;
   int total_minutos = minutos + (horas * MINUTOS_POR_HORA);
   printf("Se passaram %d minutos desde o início do dia\n", total_minutos);
   printf("%d %d\n", horas, minutos);

   return 0;
}
