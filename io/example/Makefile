CC=gcc
CFLAGS=-Wno-asm-operand-widths
SOURCES=tryio
LIBDIR=-Ibin/
LIBS=../out.c

all: compfile runfile complit

compfile:
	@$(CC) $(SOURCES).c $(LIBS) $(CFLAGS) -o $(SOURCES)

runfile:
	@./$(SOURCES)

complit:
	@echo "`tput setaf 2`COMPLETED!`tput sgr0`\n"