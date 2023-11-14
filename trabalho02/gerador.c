#include "pessoa.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
   if (argc < 3)
   {
      puts("Forneça o caminho do arquivo texto como primeiro parâmetro do programa");
      puts("e o caminho do arquivo binário como segundo parâmetro do programa!");
      return EXIT_FAILURE;
   }

   const char *CAMINHO_ARQUIVO_TEXTO = argv[1];
   Pessoa *lista = alocar_lista_pessoas_de_arquivo_texto(CAMINHO_ARQUIVO_TEXTO);

   // imprimir_lista_pessoas(lista);

   const char *CAMINHO_ARQUIVO_BINARIO = argv[2];
   gravar_lista_pessoas_no_arquivo_binario(lista, CAMINHO_ARQUIVO_BINARIO);

   desalocar_lista_pessoas(lista);
   return EXIT_SUCCESS;
}
