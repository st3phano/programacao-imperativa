#include "arquivo.h"
#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   if (argc < 3)
   {
      puts("Forneça o caminho do arquivo binário como primeiro parâmetro do programa\n"
           "e o caminho do arquivo texto como segundo parâmetro do programa!");
      return EXIT_FAILURE;
   }
   const char *CAMINHO_ARQUIVO_BINARIO = argv[1];
   const char *CAMINHO_ARQUIVO_TEXTO = argv[2];

   if (converter_arquivo_tipo1_em_tipo2(CAMINHO_ARQUIVO_BINARIO, BINARIO, CAMINHO_ARQUIVO_TEXTO, TEXTO))
   {
      puts("Converteu o arquivo binário em texto com sucesso!");
   }
   else
   {
      puts("Houve um problema ao converter o arquivo binário em texto\n"
           "o arquivo texto pode estar corrompido!");
   }

   return EXIT_SUCCESS;
}
