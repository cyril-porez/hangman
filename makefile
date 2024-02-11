all:
	gcc -Wall -Wextra -Werror .\main.c split.c trim.c listChain.c rules.c potence.c readFile.c  -o hangman