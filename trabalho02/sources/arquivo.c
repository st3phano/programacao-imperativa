#include "arquivo.h"
#include <stdio.h>

FILE *abrir_arquivo(const char *caminho_arquivo, const char *modo)
{
   FILE *arquivo = fopen(caminho_arquivo, modo);
   if (arquivo == NULL)
   {
      printf("Falha ao abrir o arquivo '%s'\n", caminho_arquivo);
   }

   return arquivo;
}
