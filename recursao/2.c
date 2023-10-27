#include <stdio.h>

void imprimir_fatorial(int n)
{
   if (n < 0)
   {
      puts("0");
   }
   else if (n <= 1)
   {
      puts("1");
   }
   else
   {
      printf("%d.", n);
      imprimir_fatorial(n - 1);
   }
}

int main(void)
{
   imprimir_fatorial(5);

   return 0;
}
