#include "menu.h"
#include "arquivo.h"
#include "pessoa.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exibir_menu(void)
{
   printf("\n    Escolha uma opção:\n"
          "[%d] Inserir uma nova 'Pessoa'\n"
          "[%d] Remover uma 'Pessoa'\n"
          "[%d] Exibir uma 'Pessoa'\n"
          "[%d] Listar todas as 'Pessoa's\n"
          "[%d] Gravar alterações\n"
          "[%d] Gravar alterações e encerrar\n",
          INSERIR, REMOVER, EXIBIR, LISTAR, GRAVAR, ENCERRAR);
}

bool executar_opcao_menu_inserir(Pessoa **lista_ligada)
{
   Pessoa *pessoa = ler_pessoa_da_entrada_padrao();
   if (pessoa == NULL)
   {
      puts("Não foi possível criar uma nova 'Pessoa'!");
      exit(EXIT_FAILURE);
   }

   bool lista_alterada = inserir_pessoa_na_lista_ligada(lista_ligada, pessoa);
   if (lista_alterada)
   {
      printf("'Pessoa' com ID = %d e Nome = '%s' inserida com sucesso!\n", pessoa->id, pessoa->nome);
   }
   else
   {
      printf("Não foi possível inserir, já existe uma 'Pessoa' com ID = %d!\n", pessoa->id);
      free(pessoa);
      pessoa = NULL;
   }

   return lista_alterada;
}

bool executar_opcao_menu_remover(Pessoa **lista_ligada)
{
   int id_pessoa = ler_inteiro_da_entrada_padrao("Digite o ID da 'Pessoa' que deseja remover: ",
                                                 MAX_DIGITOS_ID_PESSOA);

   bool lista_alterada = remover_pessoa_da_lista_ligada(lista_ligada, id_pessoa);
   if (lista_alterada)
   {
      printf("'Pessoa' com ID = %d removida com sucesso!\n", id_pessoa);
   }
   else
   {
      printf("Não foi possível remover, 'Pessoa' com ID = %d não existe!\n", id_pessoa);
   }

   return lista_alterada;
}

void executar_opcao_menu_exibir(Pessoa *inicio_lista_ligada)
{
   int id_pessoa = ler_inteiro_da_entrada_padrao("Digite o ID da 'Pessoa' que deseja exibir: ",
                                                 MAX_DIGITOS_ID_PESSOA);

   Pessoa *pessoa = encontrar_pessoa_na_lista_ligada(inicio_lista_ligada, id_pessoa);
   if (pessoa != NULL)
   {
      imprimir_pessoa(pessoa);
      putchar('\n');
   }
   else
   {
      printf("'Pessoa' com ID = %d não existe!\n", id_pessoa);
   }
}

void executar_opcao_menu_gravar(Pessoa *inicio_lista_ligada, const char *caminho_arquivo_gravar)
{
   bool gravou = gravar_lista_ligada_pessoas_em_arquivo(inicio_lista_ligada, caminho_arquivo_gravar, BINARIO);

   if (gravou)
   {
      printf("Alterações gravadas no arquivo '%s' com sucesso!\n", caminho_arquivo_gravar);
   }
   else
   {
      printf("Houve um problema ao gravar no arquivo '%s'\n"
             "o arquivo pode estar corrompido!\n",
             caminho_arquivo_gravar);
   }
}

Pessoa *ler_pessoa_da_entrada_padrao(void)
{
   Pessoa *pessoa = malloc(sizeof(*pessoa));
   if (pessoa == NULL)
   {
      puts("Falha ao alocar memória para 'Pessoa'!");
      return NULL;
   }

   pessoa->id = ler_inteiro_da_entrada_padrao("Digite um ID para a pessoa: ", MAX_DIGITOS_ID_PESSOA);
   ler_string_da_entrada_padrao("Digite o nome da pessoa: ", pessoa->nome, TAMANHO_BUFFER_NOME_PESSOA);
   pessoa->proxima = NULL;

   return pessoa;
}

int ler_inteiro_da_entrada_padrao(const char *prompt, int max_digitos_inteiro)
{
   int inteiro = INT_MIN;

   do
   {
      printf("%s", prompt);

      char formato_scanf[32];
      sprintf(formato_scanf, "%%%dd", max_digitos_inteiro);

      scanf(formato_scanf, &inteiro);
      limpar_entrada_padrao();
   } while (inteiro == INT_MIN);

   return inteiro;
}

void ler_string_da_entrada_padrao(const char *prompt, char *buffer, int tamanho_buffer)
{
   do
   {
      printf("%s", prompt);

      char formato_scanf[32];
      sprintf(formato_scanf, "%%%d[^\r\n]", tamanho_buffer - 1);

      scanf(formato_scanf, buffer);
      limpar_entrada_padrao();
   } while (strlen(buffer) == 0);
}

void limpar_entrada_padrao(void)
{
   char ch;
   do
   {
      ch = getchar();
   } while (ch != '\n' && ch != EOF);
}
