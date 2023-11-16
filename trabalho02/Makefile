CC = clang
CFLAGS = -Wno-deprecated-declarations -Wall -Wextra -Werror -std=c99 -Iheaders
RM = rm -f

SRCS_GERADOR = gerador.c sources/arquivo.c sources/pessoa.c
OBJS_GERADOR = $(SRCS_GERADOR:.c=.o)
EXE_GERADOR = gerador.exe

SRCS_EXPORTADOR = exportador.c sources/arquivo.c sources/pessoa.c
OBJS_EXPORTADOR = $(SRCS_EXPORTADOR:.c=.o)
EXE_EXPORTADOR = exportador.exe

SRCS_EDITOR = editor.c sources/arquivo.c sources/menu.c sources/pessoa.c
OBJS_EDITOR = $(SRCS_EDITOR:.c=.o)
EXE_EDITOR = editor.exe

all: $(EXE_GERADOR) $(EXE_EXPORTADOR) $(EXE_EDITOR)

$(EXE_GERADOR): $(OBJS_GERADOR)
	$(CC) $(CFLAGS) $(OBJS_GERADOR) -o $@

$(EXE_EXPORTADOR): $(OBJS_EXPORTADOR)
	$(CC) $(CFLAGS) $(OBJS_EXPORTADOR) -o $@

$(EXE_EDITOR): $(OBJS_EDITOR)
	$(CC) $(CFLAGS) $(OBJS_EDITOR) -o $@

clean:
	$(RM) $(OBJS_GERADOR) $(OBJS_EXPORTADOR) $(OBJS_EDITOR)

fclean: clean
	$(RM) $(EXE_GERADOR) $(EXE_EXPORTADOR) $(EXE_EDITOR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
