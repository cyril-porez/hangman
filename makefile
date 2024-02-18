TARGET = hangman

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c split.c trim.c listChain.c rules.c potence.c readFile.c tabListScore.c

OBJ = $(SRC:.c=.o)

all:
	$(TARGET)

$(TARGET): $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
		./$(TARGET) $(ARG1) $(ARG2) $(ARG3)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(TARGET)

.PHONY: all clean fclean run