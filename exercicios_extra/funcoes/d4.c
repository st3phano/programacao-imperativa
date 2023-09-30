/**
 * Escreva uma função na linguagem C com o seguinte protótipo:
 * void transpor(double* matriz_ptr, int linhas, int colunas, double* transposta_ptr)
 * A função deve gerar a matriz transposta de uma matriz de valores reais recebida
 * como parâmetro. O primeiro parâmetro aponta para o elemento da matriz na sua
 * primeira linha e primeira coluna. O segundo parâmetro indica a quantidade de
 * linhas da matriz original, enquanto o segundo parâmetro indica a quantidade de
 * colunas. O quarto parâmetro indica onde deve ser armazenada a matriz transposta.
 */

#include <stdio.h>

void transpor(double *matriz_ptr, int linhas, int colunas, double *transposta_ptr)
{
   for (int linha = 0; linha < linhas; ++linha)
   {
      for (int coluna = 0; coluna < colunas; ++coluna)
      {
         transposta_ptr[(coluna * linhas) + linha] = matriz_ptr[(linha * colunas) + coluna];
      }
   }
}

#define LINHAS 2
#define COLUNAS 3

int main(void)
{
   double matriz[LINHAS * COLUNAS] = {2, 3, 4,
                                      5, 6, 7};
   double matriz_transposta[COLUNAS * LINHAS];
   transpor(matriz, LINHAS, COLUNAS, matriz_transposta);

   const int LINHAS_TRANSPOSTA = COLUNAS;
   const int COLUNAS_TRANSPOSTA = LINHAS;
   for (int linha = 0; linha < LINHAS_TRANSPOSTA; ++linha)
   {
      for (int coluna = 0; coluna < COLUNAS_TRANSPOSTA; ++coluna)
      {
         printf("%.1f ", matriz_transposta[(linha * COLUNAS_TRANSPOSTA) + coluna]);
      }
      putchar('\n');
   }

   return 0;
}
