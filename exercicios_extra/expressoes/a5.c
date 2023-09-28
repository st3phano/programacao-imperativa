/**
 * Escreva um programa na Linguagem C que efetue o cálculo do volume de
 * combustível gasto em uma viagem, sabendo-se que o carro faz 12 km com um litro de
 * combustível. Deverão ser fornecidos como entrada do programa os seguintes dados: o
 * tempo gasto na viagem e a velocidade média.
 * Distância = Tempo x Velocidade
 * Volume = Distância / 12
 * O programa deverá exibir a distância percorrida e o volume de combustível gasto na
 * viagem.
 */

#include <stdio.h>

int main(void)
{
   printf("%s", "Digite o tempo gasto na viagem (horas): ");
   double tempo_gasto_horas = 0;
   scanf("%lf", &tempo_gasto_horas);

   printf("%s", "Digite a velocidade média durante a viagem (km/h): ");
   double velocidade_media_km_h = 0;
   scanf("%lf", &velocidade_media_km_h);

   double distancia_percorrida_km = tempo_gasto_horas * velocidade_media_km_h;
   printf("Foram percorridos %.2f quilômetros\n", distancia_percorrida_km);

   const double KM_POR_LITRO_COMBUSTIVEL = 12;
   double volume_combustivel_gasto_litros = distancia_percorrida_km / KM_POR_LITRO_COMBUSTIVEL;
   printf("Foram gastos %.2f litros de combustível\n", volume_combustivel_gasto_litros);

   return 0;
}
