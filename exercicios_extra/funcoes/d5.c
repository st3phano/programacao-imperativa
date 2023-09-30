/**
 * O código a seguir define apenas a função main, a qual chama outras funções a fim
 * de resolver uma Equação do segundo grau qualquer, dados os seus três coeficientes.
 * #include <stdio.h>
 * int main()
 * {
 *    printf("Forma geral da equação do segundo grau: a x**2 + b x + c = 0\n");
 *    double coef_a = obter_coeficiente("Digite o coeficiente a: ");
 *    if (coef_a == 0)
 *    {
 *       printf("O coeficiente a não pode ser zero!\n");
 *       return 0;
 *    }
 *    double coef_b = obter_coeficiente("Digite o coeficiente b: ");
 *    double coef_c = obter_coeficiente("Digite o coeficiente c: ");
 *    double delta = calcular_delta(coef_a, coef_b, coef_c);
 *    if (delta < 0)
 *       responder_sem_raiz();
 *    else if (delta == 0)
 *       responder_uma_raiz(coef_a, coef_b);
 *    else
 *       responder_duas_raizes(coef_a, coef_b, delta);
 *    return 0;
 * }
 * Complete o código com a definição de todas as funções necessárias para que o
 * código compile e execute corretamente.
 */

#include <math.h>
#include <stdio.h>

double obter_coeficiente(const char *requisicao)
{
   printf("%s", requisicao);
   double coeficiente = 0;
   scanf("%lf", &coeficiente);

   return coeficiente;
}

double calcular_delta(double coeficiente_a, double coeficiente_b, double coeficiente_c)
{
   return (coeficiente_b * coeficiente_b) - (4 * coeficiente_a * coeficiente_c);
}

void responder_sem_raiz()
{
   puts("A equação não possui raízes reais.");
}

void responder_uma_raiz(double coeficiente_a, double coeficiente_b)
{
   double raiz = -coeficiente_b / (2 * coeficiente_a);
   printf("A equação possui somente uma raiz: %f.\n", raiz);
}

void responder_duas_raizes(double coeficiente_a, double coeficiente_b, double delta)
{
   double raiz_1 = (-coeficiente_b + sqrt(delta)) / (2 * coeficiente_a);
   double raiz_2 = (-coeficiente_b - sqrt(delta)) / (2 * coeficiente_a);

   printf("A equação possui duas raízes: %f e %f.\n", raiz_1, raiz_2);
}

int main()
{
   printf("Forma geral da equação do segundo grau: a x**2 + b x + c =  0\n");

   double coef_a = obter_coeficiente("Digite o coeficiente a: ");
   if (coef_a == 0)
   {
      printf("O coeficiente a não pode ser zero!\n");
      return 0;
   }
   double coef_b = obter_coeficiente("Digite o coeficiente b: ");
   double coef_c = obter_coeficiente("Digite o coeficiente c: ");

   double delta = calcular_delta(coef_a, coef_b, coef_c);
   if (delta < 0)
      responder_sem_raiz();
   else if (delta == 0)
      responder_uma_raiz(coef_a, coef_b);
   else
      responder_duas_raizes(coef_a, coef_b, delta);

   return 0;
}
