#include <stdio.h>

void imprimir_string_invertida(const char *string)
{
   if (*string != '\0')
   {
      imprimir_string_invertida(string + 1);
   }

   putchar(*string);
}

int main(void)
{
   imprimir_string_invertida("Minha string!");

   return 0;
}
