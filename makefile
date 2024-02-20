TARGET = hangman

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I/mingw64/include -IfichierC
LDFLAGS = -L/mingw64/lib -lncurses

SRC = main.c fichierC/split.c fichierC/trim.c fichierC/listChain.c fichierC/rules.c fichierC/potence.c fichierC/readFile.c fichierC/tabListScore.c

OBJ = $(SRC:.c=.o)

all:
	$(TARGET)

$(TARGET): $(OBJ)
		$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
		./$(TARGET) $(ARG1) $(ARG2) $(ARG3)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(TARGET)

.PHONY: all clean fclean run