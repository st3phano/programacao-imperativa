/**
 * Escreva uma função na linguagem C com o seguinte protótipo:
 * typedef struct { char nome[40]; int idade; } Pessoa;
 * void preencher(Pessoa* p)
 * A função deve preencher os campos da estrutura recebida como parâmetro a partir
 * de dados fornecidos pelo usuário via teclado.
 * Deve ser escrita uma função main para verificar o funcionamento da função preencher.
 */

#include <stdio.h>

typedef struct
{
   char nome[40];
   int idade;
} Pessoa;

void preencher(Pessoa *p)
{
   printf("%s", "Digite o nome: ");
   scanf("%39[^\r\n]", p->nome);

   while (getchar() != '\n')
      continue;

   printf("%s", "Digite a idade: ");
   scanf("%d", &(p->idade));
}

int main(void)
{
   Pessoa pessoa;
   preencher(&pessoa);

   printf("%s\n", pessoa.nome);
   printf("%d\n", pessoa.idade);

   return 0;
}
