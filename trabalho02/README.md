Para compilar o GERADOR...
<br>
make gerador.exe
<br>
OU
<br>
clang -Wno-deprecated-declarations -Wall -Wextra -Werror -std=c99 -Iheaders sources/*.c gerador.c -o gerador.exe
<br>

Para compilar o EXPORTADOR...
<br>
make exportador.exe
<br>
OU
<br>
clang -Wno-deprecated-declarations -Wall -Wextra -Werror -std=c99 -Iheaders sources/*.c exportador.c -o exportador.exe
<br>

Para compilar o EDITOR...
<br>
make editor.exe
<br>
OU
<br>
clang -Wno-deprecated-declarations  -Wall -Wextra -Werror -std=c99 -Iheaders sources/*.c editor.c -o editor.exe
<br>
