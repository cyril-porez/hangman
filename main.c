#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void potence() {
  printf("%s","\n  -----\n");
  printf("%s","  |   |\n");
  printf("%s","  0   |\n");
  printf("%s"," /|\\  |\n");
  printf("%s"," / \\  |\n");
  printf("%s","      |\n");
  printf("%s","--------\n");
}


char **split(char *str, char *charset);
void trim(char *str);

int main(int argc, char *argv[]) {  
  printf("%d\n", argc);
  printf("argv[2] %s\n\n", argv[2]);

  FILE *file;
  file = fopen(argv[1], "r");

  int nbrLines = 0;
  int numeroLine = 1;
  int categoryWord = 0;
  char line[100];
  int wordError = 0;

  if (file == NULL)
  {
    perror("erreur lors de l'ouverture du fichier");
    printf("%s", "error" );
    return 1;
  }

  int countWord = 0;
  while (fgets(line, sizeof(line), file) != NULL) 
  {
    if (line[0] == '#') 
    {
        categoryWord++;
    }
    if (line[0] != '#') {
      
      int i = 0;
      while (line[i] != '\0')
      {
        if ((line[i] != ',' && line[i] != '\t' && line[i] != '\n') && 
        (line[i+1] == ',' || line[i+1] == '\t' || line[i+1] == '\n' || line[i+1] == '\0')) 
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
        // printf("words[2] => %s", words[2]);
        if (strcmp(words[2], "facile") != 0 && strcmp(words[2], "moyen") != 0 && strcmp(words[2], "difficile") != 0) 
        {
            wordError++;
            fprintf(stderr, "Error on line %d : %s", numeroLine, line);
        }
      }
      countWord = 0;
    }
    numeroLine++;
    nbrLines++;
  }
  if (wordError == nbrLines - categoryWord)
  {
      fprintf(stderr, "\n%s : invalid file.", argv[1]);
  }

  printf("\n%d", categoryWord);
  printf("\n%d", wordError);
  printf("\nnombre de ligne => %d \n", nbrLines);

  fclose(file);
  potence();
  return 0;
}