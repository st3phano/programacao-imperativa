#include <stdio.h>

unsigned calcular_termo_fibonacci(unsigned termo)
{
   if (termo == 0 || termo == 1)
   {
      return termo;
   }

   return calcular_termo_fibonacci(termo - 1) + calcular_termo_fibonacci(termo - 2);
}

int main(void)
{
   unsigned n = 9;
   printf("%u termo: %u", n, calcular_termo_fibonacci(n));

   return 0;
}
