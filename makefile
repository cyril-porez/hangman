TARGET = hangman

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I/mingw64/include
LDFLAGS = -L/mingw64/lib -lncurses

SRC = main.c split.c trim.c listChain.c rules.c potence.c readFile.c tabListScore.c

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