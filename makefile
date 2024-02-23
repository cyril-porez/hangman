TARGET = hangman

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I/mingw64/include -IfichierC -g3
LDFLAGS = -L/mingw64/lib -lncurses

# CFLAGS = -Wall -Wextra -Werror -IfichierC 
# LDFLAGS = -L/mingw64/lib -lncurses

# ifeq ($(OS),Windows_NT)
#     CFLAGS += -I/mingw64/include
#     LDFLAGS = -L/mingw64/lib -lncurses
# endif

# CFLAGS += $(shell pkg-config --cflags ncursesw)
# LDFLAGS += $(shell pkg-config --libs ncursesw)

SRC = main.c \
			fichierC/split.c \
			fichierC/trim.c \
			fichierC/listChain.c \
			fichierC/rules.c \
			fichierC/potence.c \
			fichierC/readFile.c \
			fichierC/tabListScore.c \
			fichierC/hangman.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
		$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
		./$(TARGET) $(ARG1) $(ARG2) $(ARG3)

valgrind: $(TARGET)
				valgrind --leak-check=full --tool=memcheck --log-file=./valgrind.log --vgdb=yes ./$(TARGET) $(ARG1) $(ARG2) $(ARG3)


clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(TARGET)

.PHONY: all clean fclean run valgrind