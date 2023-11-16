#include "arquivo.h"
#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   if (argc < 3)
   {
      puts("Forneça o caminho do arquivo texto como primeiro parâmetro do programa\n"
           "e o caminho do arquivo binário como segundo parâmetro do programa!");
      return EXIT_FAILURE;
   }
   const char *CAMINHO_ARQUIVO_TEXTO = argv[1];
   const char *CAMINHO_ARQUIVO_BINARIO = argv[2];

   if (converter_arquivo_tipo1_em_tipo2(CAMINHO_ARQUIVO_TEXTO, TEXTO, CAMINHO_ARQUIVO_BINARIO, BINARIO))
   {
      puts("Converteu o arquivo texto em binário com sucesso!");
   }
   else
   {
      puts("Houve um problema ao converter o arquivo texto em binário\n"
           "o arquivo binário pode estar corrompido!");
   }

   return EXIT_SUCCESS;
}
