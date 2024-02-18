#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "listChain.h"
#include "tabListScore.h"

char **split(char *str, char *charset);
void trim(char *str);
void rules();
void potence(char *findWord, int error, int tryWord, int tryCharacter);
Node *readFileDirectory(char *filename, char *difficulty, char *category);
void addScore(ScoreBoard *sb, const char *nom, int score, const char *difficulty);
void displayScore(FILE *file, Score *scores, int size);
int compareScore(const void *a, const void *b);

void readFileScore(ScoreBoard *sb)
{
	FILE *file = fopen("score.txt", "r");
	char line[100];

	if (!fgets(line, sizeof(line), file))
	{
		fclose(file);
		exit(1);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		char **test = split(line, " ");
		if (test != NULL)
		{
			trim(test[0]);
			trim(test[1]);
			trim(test[2]);
			char *name = test[0];
			int score = atoi(test[1]);
			char *level = test[2];

			addScore(sb, name, score, level);
		}
	}

	fclose(file);
}

void fileScore(ScoreBoard *sb, char *name, int score, char *difficulty)
{
	FILE *file = fopen("score.txt", "w");

	if (file != NULL)
	{
		addScore(sb, name, score, difficulty);

		qsort(sb->hard, sb->sizeHard, sizeof(Score), compareScore);
		qsort(sb->middle, sb->sizeMiddle, sizeof(Score), compareScore);
		qsort(sb->easy, sb->sizeEasy, sizeof(Score), compareScore);
		fprintf(file, "USERNAME        SCORE        LEVEL");
		displayScore(file, sb->hard, sb->sizeHard);
		displayScore(file, sb->middle, sb->sizeMiddle);
		displayScore(file, sb->easy, sb->sizeEasy);

		fclose(file);
	}
	else
	{
		printf("erreur de l'ouverture du fichier.");
	}
}

char *maskWord(char *word)
{
	char *maskWord = malloc(strlen(word) + 1);
	if (maskWord != NULL)
	{
		strcpy(maskWord, word);
		int len = strlen(word);

		if (len > 2)
		{
			for (int i = 1; i < len - 1; i++)
			{
				maskWord[i] = '*';
			}
		}
	}
	return maskWord;
}

int main(int argc, char *argv[])
{
	char *dictionnary = argc > 2 ? argv[1] : "C:\\Users\\porez\\OneDrive\\Bureau\\hangman\\dictionnaire.txt";
	char *difficulty = argc >= 3 ? argv[2] : NULL;
	char *category = argc == 4 ? argv[3] : NULL;
	ScoreBoard sb = {0};

	if (difficulty != NULL && (strcmp(difficulty, "facile") != 0 && strcmp(difficulty, "moyen") != 0 && strcmp(difficulty, "difficile") != 0))
	{
		printf("Le niveau de difficulte doit etre facile, moyen, difficile !!");
		exit(1);
	}

	readFileScore(&sb);

	rules();

	bool test = true;
	char yesNo;
	while (test)
	{
		Node *listChain = readFileDirectory(dictionnary, difficulty, category);

		char *findWord = getRandomElement(listChain);
		char *maskedWord = maskWord(findWord), str[50];
		bool victory = false, tru = true;
		int error = 0, len = 0, tryWord = 3, tryCharacter = 6, attemptNbr = 0;

		while (tru)
		{
			potence(maskedWord, error, tryWord, tryCharacter);

			if (tryWord == 0 && tryCharacter == 0)
			{
				printf("Plus d'essais disponibles. Fin du jeu.\n");
				tru = false;
			}

			if (error < 9)
			{
				while (1)
				{
					printf("\nEntrer un mot ou un caractere : ");
					fflush(stdout);
					fgets(str, sizeof(str), stdin);
					str[strcspn(str, "\n")] = 0;
					len = strlen(str);

					if ((tryWord > 0 && len > 2) || (tryCharacter > 0 && len == 1))
					{
						attemptNbr++;
						printf("%d", attemptNbr);
						break;
					}
					else if (tryWord == 0 && len > 2)
					{
						printf("Vous n'avez plus d'essai pour entrer un mot!\n");
					}
					else if (tryCharacter == 0 && len == 1)
					{
						printf("Vous n'avez plus d'essai pour entrer un caractere!\n");
					}
					else
					{
						printf("Entree non valide, veuillez reessayer.\n");
					}
				}
			}

			if (len == 1)
			{
				int i = 1;
				int sizeFindWord = strlen(findWord);
				bool find = false;
				while (i <= sizeFindWord - 2)
				{
					if (findWord[i] == str[0])
					{
						find = true;
						maskedWord[i] = str[0];
					}
					i++;
				}
				if (strcmp(maskedWord, findWord) == 0)
				{
					potence(maskedWord, error, tryWord, tryCharacter);
					printf("You Win !!!\n");
					tru = false;
					victory = true;
				}

				if (find == false)
				{
					tryCharacter--;
					error++;
				}
			}

			if (len > 1)
			{
				if (strcmp(str, findWord) == 0)
				{
					potence(maskedWord, error, tryWord, tryCharacter);
					printf("YOU WIN !!!\n");
					victory = true;
					tru = false;
				}
				else
				{
					tryWord--;
					error++;
				}
			}
		}
		if (victory == true)
		{
			char writeScore;
			printf("Souhaitez-vous inscrire votre score? (Y/N) ");
			scanf("%c", &writeScore);
			if (writeScore == 'Y')
			{
				char name[20];
				printf("Veuiler entrer votre nom !");
				scanf("%s", name);
				printf("\n%s  %d   %s", name, attemptNbr, difficulty);
				fileScore(&sb, name, attemptNbr, difficulty);
			}
			printf("OK\n");
		}

		printf("Souhaitez-vous relancer une partie? (Y/N) ");
		scanf(" %c", &yesNo);
		while ((getchar()) != '\n')
			;
		test = yesNo == 'N' ? false : true;
	}
	return 0;
}