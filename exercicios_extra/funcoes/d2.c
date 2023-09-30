/**
 * Escreva uma função na linguagem C com o seguinte protótipo:
 * int calcular_hash(char* texto, int modulo)
 * A função deve calcular o valor de hash correspondente ao texto fornecido como
 * parâmetro. O cálculo deve, primeiramente, fazer a somatória dos valores ASCII de
 * todos os caracteres do texto e, em seguida, obter o resto da divisão pelo módulo
 * fornecido como parâmetro.
 * Deve ser escrita uma função main para verificar o funcionamento da função calcular_hash.
 * O valor fornecido como módulo deve estar no intervalo [106, 107].
 */

#include <stdio.h>

int calcular_hash(char *texto, int modulo)
{
   int soma_texto = 0;
   while (*texto != '\0')
   {
      soma_texto += *texto;
      ++texto;
   }

   return soma_texto % modulo;
}

int main(void)
{
   printf("%d\n", calcular_hash("int calcular_hash(char* texto, int modulo)", 106));
   printf("%d\n", calcular_hash("int calcular_hash(char* texto, int modulo)", 107));

   return 0;
}
