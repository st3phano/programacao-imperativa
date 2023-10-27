#include <stdio.h>

void imprimir_torre_hanoi(unsigned discos,
                          const char *pino_origem,
                          const char *pino_auxiliar,
                          const char *pino_destino)
{
   if (discos == 0)
   {
      return;
   }

   imprimir_torre_hanoi(discos - 1, pino_origem, pino_destino, pino_auxiliar);
   printf("Move um disco de %s para %s\n", pino_origem, pino_destino);
   imprimir_torre_hanoi(discos - 1, pino_auxiliar, pino_origem, pino_destino);
}

int main(void)
{
   imprimir_torre_hanoi(2, "ORIGEM", "AUXILIAR", "DESTINO");
   return 0;
}
