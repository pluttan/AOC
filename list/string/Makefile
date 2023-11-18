CC=gcc
CFLAGS=-Wno-asm-operand-widths -Wno-incompatible-library-redeclaration
SOURCES=string
LIBS=../../io/out.c  ../../mem/al.c ../../math/math.c

all: compfile runfile complit

compfile:
	@$(CC) $(SOURCES).c $(LIBS) $(CFLAGS) -o $(SOURCES)

runfile:
	@./$(SOURCES)

complit:
	@echo "`tput setaf 2`COMPLETED!`tput sgr0`\n"