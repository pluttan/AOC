all: README.md complit

README.md: $(wildcard *.md)
	@cat $^ > ../$@

complit:
	@echo "`tput setaf 2`COMPLETED!`tput sgr0`\n"

.PHONY: clean complit

clean:
	rm -f ../README.md
