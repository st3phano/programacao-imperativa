/**
 * Em certo país, as placas dos veículos possuem quatro algarismos, sendo:
 * • O primeiro algarismo corresponde a um estado do país
 * • O segundo algarismo corresponde a uma cidade daquele estado
 * • O terceiro e o quarto algarismos formam o número do veículo em sua cidade
 * Por exemplo, o veículo com placa 5832 indica que está registrado no estado 5, na
 * cidade 8 (do estado 5) e tem o número 32 na cidade.
 * Escreva um programa na Linguagem C (contendo apenas a função main) que leia um
 * valor inteiro de quatro algarismos correspondente à placa de um veículo e imprima
 * separadamente o número do estado, o número da cidade no estado e o número do
 * veículo na cidade.
 * IMPORTANTE: O resultado da leitura do número da placa do veículo tem,
 * necessariamente, que ser armazenado em uma variável de um dos seguintes tipos:
 * unsigned int ou unsigned short. Assim, o programa deverá usar as operações de
 * divisão inteira e resto de divisão.
 */

#include <stdio.h>

int main(void)
{
   printf("%s", "Digite a placa do veículo: ");
   unsigned placa_veiculo = 0;
   scanf("%u", &placa_veiculo);
   unsigned resto_placa_veiculo = placa_veiculo;

   const unsigned DIVISOR_ESTADO_VEICULO = 1000;
   unsigned estado_veiculo = resto_placa_veiculo / DIVISOR_ESTADO_VEICULO;
   resto_placa_veiculo %= DIVISOR_ESTADO_VEICULO;
   printf("Estado: %u\n", estado_veiculo);

   const unsigned DIVISOR_CIDADE_VEICULO = 100;
   unsigned cidade_veiculo = resto_placa_veiculo / DIVISOR_CIDADE_VEICULO;
   resto_placa_veiculo %= DIVISOR_CIDADE_VEICULO;
   printf("Cidade: %u\n", cidade_veiculo);

   printf("Número do veículo: %u\n", resto_placa_veiculo);

   return 0;
}
