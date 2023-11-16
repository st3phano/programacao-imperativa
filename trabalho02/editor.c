#include "arquivo.h"
#include "menu.h"
#include "pessoa.h"
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   if (argc < 2)
   {
      puts("Forneça o caminho do arquivo binário como primeiro parâmetro do programa!");
      return EXIT_FAILURE;
   }
   const char *CAMINHO_ARQUIVO_BINARIO = argv[1];

   Pessoa *lista = alocar_lista_ligada_pessoas_de_arquivo(CAMINHO_ARQUIVO_BINARIO, BINARIO);
   bool lista_alterada = false;

   int opcao_menu = ENCERRAR;
   do
   {
      exibir_menu();

      opcao_menu = ler_inteiro_da_entrada_padrao(": ", 9);
      switch (opcao_menu)
      {
      case INSERIR:
      {
         lista_alterada = executar_opcao_menu_inserir(&lista);
         break;
      }
      case REMOVER:
      {
         lista_alterada = executar_opcao_menu_remover(&lista);
         break;
      }
      case EXIBIR:
      {
         executar_opcao_menu_exibir(lista);
         break;
      }
      case LISTAR:
      {
         imprimir_lista_ligada_pessoas(lista);
         break;
      }
      case ENCERRAR: // fall through
      case GRAVAR:
      {
         if (lista_alterada)
         {
            executar_opcao_menu_gravar(lista, CAMINHO_ARQUIVO_BINARIO);
         }
         else
         {
            puts("Não há alterações para serem gravadas!");
         }
         break;
      }
      default:
         puts("Opção inválida!");
      }
   } while (opcao_menu != ENCERRAR);

   puts("Isso é tutudo, pepessoal!");
   desalocar_lista_ligada_pessoas(lista);
   return EXIT_SUCCESS;
}
