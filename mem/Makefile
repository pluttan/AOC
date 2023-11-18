CC=gcc
CFLAGS=-Wno-asm-operand-widths
SOURCES=al
LIBS=../io/out.c

all: compfile runfile complit

compfile:
	@$(CC) $(SOURCES).c $(LIBS) $(CFLAGS) -o $(SOURCES)

runfile:
	@./$(SOURCES)

complit:
	@echo "`tput setaf 2`COMPLETED!`tput sgr0`\n"