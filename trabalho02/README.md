Para compilar o GERADOR... <br>

com clang: <br>
clang -Iheaders sources/*.c gerador.c -o gerador.exe

com clang-cl: <br>
clang-cl -Wno-deprecated-declarations -Iheaders sources/*.c gerador.c -o gerador.exe

com gcc: <br>
gcc -Iheaders sources/*.c gerador.c -o gerador.exe
