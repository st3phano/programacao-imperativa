/**
 * Reescreva o programa abaixo fazendo a substituição do comando switch
 * por um ou mais comandos if (e respectivo else, quando se aplicar).
 *
 * #include <stdio.h>
 * int main()
 * {
 *    int k;
 *    char ch, crip;
 *    printf("Digite um número inteiro: ");
 *    scanf("%d", &k);
 *    getchar(); // consome o ENTER
 *
 *    printf("Digite um caracter: ");
 *    ch = getchar();
 *
 *    switch (k)
 *    {
 *    case 1:
 *    case 2:
 *       crip = ch + 2;
 *       printf("%c\n", crip);
 *       break;
 *    case 3:
 *       ch = ch + 5;
 *    case 4:
 *       crip = ch - 2;
 *       printf("%c\n", crip);
 *       break;
 *    default:
 *       switch (ch)
 *       {
 *       case 'a': case 'e': case 'i': case 'o': case 'u':
 *          printf("Vogal\n");
 *          break;
 *       default:
 *          printf("Consoante\n");
 *       }
 *       break;
 *    }
 *    return 0;
 */

#include <stdio.h>

int main(void)
{
   int k;
   char ch, crip;
   printf("Digite um número inteiro: ");
   scanf("%d", &k);
   getchar(); // consome o ENTER

   printf("Digite um caractere: ");
   ch = getchar();

   if (k == 1 || k == 2)
   {
      crip = ch + 2;
      printf("%c\n", crip);
   }
   else if (k == 3)
   {
      ch = ch + 5;
   }
   else if (k == 4)
   {
      crip = ch - 2;
      printf("%c\n", crip);
   }
   else
   {
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
      {
         printf("Vogal\n");
      }
      else
      {
         printf("Consoante\n");
      }
   }

   return 0;
}
