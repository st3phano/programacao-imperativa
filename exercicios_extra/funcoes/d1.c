/**
 * Escreva uma função na linguagem C com o seguinte protótipo:
 * int contar(char* texto, char chave)
 * A função deve retornar a quantidade de ocorrências do caractere chave no texto
 * fornecido como parâmetro.
 * Deve ser escrita uma função main para verificar o funcionamento da função contar.
 */

#include <stdio.h>

int contar(char *texto, char chave)
{
   int quantidade_chave = 0;
   while (*texto != '\0')
   {
      if (*texto == chave)
      {
         ++quantidade_chave;
      }
      ++texto;
   }

   return quantidade_chave;
}

int main(void)
{
   printf("%d\n", contar("int contar(char* texto, char chave)", 'c'));

   return 0;
}
