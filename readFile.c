#include "listChain.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char **split(char *str, char *charset);
void trim(char *str);

Node *readFileDirectory(char *filename, char *difficulty, char *category)
{
  FILE *file;
  file = fopen(filename, "r");
  Node *listChain = NULL;

  int nbrLines = 0;
  int numeroLine = 1;
  int categoryWord = 0;
  char line[100];
  int wordError = 0;

  printf("test");

  if (file == NULL)
  {
    perror("\nerreur lors de l'ouverture du fichier");
    exit(1);
  }

  int countWord = 0;
  while (fgets(line, sizeof(line), file) != NULL)
  {
    if (line[0] == '#')
    {
      categoryWord++;
    }
    if (line[0] != '#')
    {
      int i = 0;
      while (line[i] != '\0')
      {
        if ((line[i] != ',' && line[i] != '\t' && line[i] != '\n') &&
            (line[i + 1] == ',' || line[i + 1] == '\t' || line[i + 1] == '\n' || line[i + 1] == '\0'))
        {
          countWord++;
        }
        i++;
      }
      if (countWord != 3)
      {
        fprintf(stderr, "Error on line %d : le nombre de mots est de %d et devrait etre de 3! \n", numeroLine, countWord);
      }

      if (countWord == 3)
      {
        char **words = split(line, ",");
        trim(words[2]);
        if (strcmp(words[2], "facile") != 0 && strcmp(words[2], "moyen") != 0 && strcmp(words[2], "difficile") != 0)
        {
          wordError++;
          fprintf(stderr, "\nError on line %d : %s\n", numeroLine, line);
        }

        if (category == NULL && difficulty == NULL)
        {
          push(&listChain, words[0]);
        }
        else if (strcmp(words[2], difficulty) == 0 && category == NULL)
        {
          printf("%s\n", words[0]);
          push(&listChain, words[0]);
        }
        else if (strcmp(words[2], difficulty) == 0 && strcmp(words[1], category) == 0)
        {
          push(&listChain, words[0]);
        }
      }
      countWord = 0;
    }
    numeroLine++;
    nbrLines++;
  }
  if (wordError == nbrLines - categoryWord)
  {
    fprintf(stderr, "\n%s : invalid file.", filename);
  }
  fclose(file);
  return listChain;
}
