CC=gcc
CFLAGS=-Wno-asm-operand-widths -Wno-incompatible-library-redeclaration -Ofast
SOURCES=string
LIBDIR=-Ibin/
LIBS=../../io/out.c \
	 ../../mem/al.c \
	 ../../math/math.c
LEAKSLOG=leaks.log

# Define color codes
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m

all: compfile runfile

compfile:
	@echo "$(BLUE)Compile file $(SOURCES).c$(RESET)"
	@$(CC) $(LIBS) $(SOURCES).c $(CFLAGS) -o $(SOURCES)
	@echo "$(GREEN)Compilation successful$(RESET)"

runfile:
	@echo "$(BLUE)Running program...$(RESET)"
	@echo "----------------------"
	@./$(SOURCES)
	@echo "\n----------------------"
	@echo "$(GREEN)COMPLETED!$(RESET)"

leaks:
	@leaks -atExit -- ./$(SOURCES) > $(LEAKSLOG) 2>&1 || true
	@if grep -q "0 leaks" "$(LEAKSLOG)"; then \
	    echo "$(GREEN)Leaks checked$(RESET)"; \
	else \
	    echo "$(RED)Potential leaks found$(RESET)"; \
		exit 1; \
	fi


