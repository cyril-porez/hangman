#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fichierH/hangman.h"
#include <ncurses.h>

void hangman(char *dictionnary, char *difficulty, char *category);

int main(int argc, char *argv[])
{
	char *dictionnary = argc > 2 ? argv[1] : "dictionnaire.csv";
	char *difficulty = argc >= 3 ? argv[2] : NULL;
	char *category = argc == 4 ? argv[3] : NULL;
	// char str[32];

	if (difficulty != NULL && (strcmp(difficulty, "facile") != 0 && strcmp(difficulty, "moyen") != 0 && strcmp(difficulty, "difficile") != 0))
	{
		printf("Le niveau de difficulte doit etre facile, moyen, difficile !!");
		exit(1);
	}
	initscr(); // Initialise le mode ncurses
	// printw("Entrer un mot: "); // Affiche un message
	// scanw("%s", str);
	// printw("%s", str);

	// refresh(); // Met à jour l'écran
	// getch();	 // Attend une entrée utilisateur
	// endwin();

	hangman(dictionnary, difficulty, category);
	return 0;
}