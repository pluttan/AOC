CC=gcc
CFLAGS=-Wno-asm-operand-widths
SOURCES=tryio
LIBDIR=-Ibin/
LIBS=../out.c

all: compfile runfile

compfile:
	@$(CC) $(SOURCES).c $(LIBS) $(CFLAGS) -o $(SOURCES)

runfile:
	@./$(SOURCES)