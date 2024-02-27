#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../fichierH/listChain.h"
#include "../fichierH/tabListScore.h"

char **split(char *str, char *charset);
void freeSplit(char **words);
void trim(char *str);
void rules();
void potence(char *findWord, char *categoryWord, int error, int tryWord, int tryCharacter);
Node *readFileDirectory(char *filename, char *difficulty, char *category);
void addScore(ScoreBoard *sb, const char *nom, int score, const char *difficulty);
void displayScore(FILE *file, Score *scores, int size);
int compareScore(const void *a, const void *b);
void freeChain(Node *head);

void readFileScore(ScoreBoard *sb)
{

  FILE *file = fopen("score.txt", "r");
  char line[100];

  if (file == NULL)
  {
    perror("\nerreur lors de l'ouverture du fichier Score.");
    exit(1);
  }

  fgets(line, sizeof(line), file);

  while (fgets(line, sizeof(line), file) != NULL)
  {
    char **splitStr = split(line, " ");
    if (splitStr != NULL)
    {
      trim(splitStr[0]);
      trim(splitStr[1]);
      trim(splitStr[2]);
      char *name = splitStr[0];
      int score = atoi(splitStr[1]);
      char *level = splitStr[2];

      addScore(sb, name, score, level);
      freeSplit(splitStr);
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
    fprintf(file, "USERNAME        SCORE        LEVEL\n");
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
        if (word[i] != ' ' && word[i] != '-')
        {
          maskWord[i] = '*';
        }
      }
    }
  }
  return maskWord;
}

void hangman(char *dictionnary, char *difficulty, char *category)
{
  ScoreBoard sb = {0};
  readFileScore(&sb);

  rules();
  Node *listChain = readFileDirectory(dictionnary, difficulty, category);

  bool test = true;
  while (test)
  {
    char *line = getRandomElement(listChain);
    char **splitLine = split(line, ",");
    trim(splitLine[0]);
    trim(splitLine[1]);
    trim(splitLine[2]);
    if (difficulty == NULL)
    {
      difficulty = splitLine[2];
    }
    char *findWord = splitLine[0], *categoryWord = splitLine[1];
    char *maskedWord = maskWord(findWord), str[50];
    bool victory = false, tru = true;
    int error = 0, len = 0, tryWord = 3, tryCharacter = 6, attemptNbr = 0;

    while (tru)
    {
      potence(maskedWord, categoryWord, error, tryWord, tryCharacter);

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
          potence(maskedWord, categoryWord, error, tryWord, tryCharacter);
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
          free(maskedWord);
          maskedWord = findWord;
          potence(maskedWord, categoryWord, error, tryWord, tryCharacter);
          printf("You Win !!!\n");
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
      char writeScore = '\0';

      while (writeScore != 'Y' && writeScore != 'N')
      {
        printf("Souhaitez-vous inscrire votre score? [Y/N] ");
        scanf(" %c", &writeScore);
        while (getchar() != '\n')
          ;

        if (writeScore == 'Y')
        {
          char name[20];
          printf("Veuiler entrer votre nom !");
          scanf("%s", name);
          fileScore(&sb, name, attemptNbr, difficulty);
        }
      }
    }

    char yesNo = '\0';
    while (yesNo != 'Y' && yesNo != 'N')
    {
      printf("Souhaitez-vous relancer une partie? [Y/N] ");
      scanf(" %c", &yesNo);
      while ((getchar()) != '\n')
        ;
    }
    test = yesNo == 'N' ? false : true;

    freeSplit(splitLine);
  }
  free(sb.easy);
  free(sb.middle);
  free(sb.hard);
  freeChain(listChain);
}