#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listChain.h"
#include <stdbool.h>

char **split(char *str, char *charset);
void trim(char *str);

char *maskWord(char *word)
{
    int len = strlen(word);

    if (len > 2)
    {
        for (int i = 1; i < len - 1; i++)
        {
            word[i] = '*';
        }
    }
    return word;
}

void rules()
{
    printf("\n======================================\n");
    printf("              JEU DU PENDU          \n");
    printf("======================================\n");
}

void potence(char *findWord, int error)
{
    printf("\n  -----        %s\n", findWord);
    printf("  |   |\n");
    switch (error)
    {
    case 1:
        printf("  0   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("--------       %s\n", findWord);
        break;
    case 2:
        printf("  0   |\n");
        printf(" /    |\n");
        printf("      |\n");
        printf("      |\n");
        printf("--------       %s\n", findWord);
        break;
    case 3:
        printf("  0   |\n");
        printf(" /|   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("--------       %s\n", findWord);
        break;
    case 4:
        printf("  0   |\n");
        printf(" /|\\  |\n");
        printf("      |\n");
        printf("      |\n");
        printf("--------       %s\n", findWord);
        break;
    case 5:
        printf("  0   |\n");
        printf(" /|\\  |\n");
        printf(" /    |\n");
        printf("      |\n");
        printf("--------       %s\n", findWord);
        break;
    case 6:
        printf("  0   |\n");
        printf(" /|\\  |\n");
        printf(" / \\  |\n");
        printf("      |\n");
        printf("--------       %s\n", findWord);
        printf("GAME OVER\n");
        break;
    default:
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("--------       %s\n", findWord);
        break;
    }
}

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

int main(int argc, char *argv[])
{
    char *dictionnary = argc > 2 ? argv[1] : "C:\\Users\\porez\\OneDrive\\Bureau\\hangman\\dictionnaire.txt";
    char *difficulty = argc >= 3 ? argv[2] : NULL;
    char *category = argc == 4 ? argv[3] : NULL;

    rules();

    bool test = true;
    char yesNo;
    while (test)
    {
        Node *listChain = readFileDirectory(dictionnary, difficulty, category);

        char *findWord = getRandomElement(listChain);
        char *word = maskWord(findWord);
        char str[50];

        bool tru = true;
        int error = 0;
        while (tru)
        {
            potence(word, error);

            if (error >= 6)
            {
                tru = false;
            }

            if (error < 6)
            {
                printf("\nEntrer un mot ou un caractere : ");
                fflush(stdout);
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = 0;
            }

            if (strcmp(str, "pomme") == 0)
            {
                tru = false;
            }
            else
            {
                error++;
            }
        }
        printf("Souhaitez-vous relancer une partie?(Y/N) ");
        scanf(" %c", &yesNo);
        while ((getchar()) != '\n')
            ;
        test = yesNo == 'N' ? false : true;
    }
    return 0;
}