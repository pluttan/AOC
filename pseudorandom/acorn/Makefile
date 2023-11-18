CC=gcc
CFLAGS=-Wno-asm-operand-widths -Wno-incompatible-library-redeclaration
SOURCES=acorn
LIBDIR=-Ibin/
LIBS=../../io/out.c ../../mem/al.c\
 ../../list/string/string.c ../../math/math.c

all: compfile runfile complit

compfile:
	@$(CC) $(LIBS) $(SOURCES).c $(CFLAGS) -o $(SOURCES)

runfile:
	@./$(SOURCES)

complit:
	@echo "`tput setaf 2`COMPLETED!`tput sgr0`\n"