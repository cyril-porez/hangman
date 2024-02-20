#include <stdio.h>

void potence(char *findWord, int error, int tryWord, int tryCharacter)
{
  switch (error)
  {
  case 1:
    printf("\n  -----        %s                         Lettre: %d\n", findWord, tryCharacter);
    printf("  |   |                                        mot: %d\n", tryWord);
    printf("  0   |\n");
    printf("      |\n");
    printf("      |\n");
    printf("      |\n");
    printf("--------       %s\n", findWord);
    break;
  case 2:
    printf("\n  -----        %s                         Lettre: %d\n", findWord, tryCharacter);
    printf("  |   |                                        mot: %d\n", tryWord);
    printf("  0   |\n");
    printf(" /    |\n");
    printf("      |\n");
    printf("      |\n");
    printf("--------       %s\n", findWord);
    break;
  case 3:
    printf("\n  -----        %s                         Lettre: %d\n", findWord, tryCharacter);
    printf("  |   |                                        mot: %d\n", tryWord);
    printf("  0   |\n");
    printf(" /|   |\n");
    printf("      |\n");
    printf("      |\n");
    printf("---------      %s\n", findWord);
    break;
  case 4:
    printf("\n  -----        %s                         Lettre: %d\n", findWord, tryCharacter);
    printf("  |   |                                        mot: %d\n", tryWord);
    printf("  0   |\n");
    printf(" /|\\  |\n");
    printf("      |\n");
    printf("      |\n");
    printf("---------      %s\n", findWord);
    break;
  case 5:
    printf("\n  -----        %s                         Lettre: %d\n", findWord, tryCharacter);
    printf("  |   |                                        mot: %d\n", tryWord);
    printf("  0   |\n");
    printf(" /|\\  |\n");
    printf(" /    |\n");
    printf("      |\n");
    printf("--------       %s\n", findWord);
    break;
  case 6:
    printf("\n  -----        %s                         Lettre: %d\n", findWord, tryCharacter);
    printf("  |   |                                        mot: %d\n", tryWord);
    printf("  0   |\n");
    printf(" /|\\  |\n");
    printf(" / \\  |\n");
    printf("      |\n");
    printf("--------       %s\n", findWord);
    break;
  case 7:
    printf("\n  -----        %s                         Lettre: %d\n", findWord, tryCharacter);
    printf("  |  \\|                                        mot: %d\n", tryWord);
    printf("  0   |\n");
    printf(" /|\\  |\n");
    printf(" / \\  |\n");
    printf("      |\n");
    printf("--------       %s\n", findWord);
    break;
  case 8:
    printf("\n  -----        %s                         Lettre: %d\n", findWord, tryCharacter);
    printf("  |  \\|                                        mot: %d\n", tryWord);
    printf("  0   |\n");
    printf(" /|\\  |\n");
    printf(" / \\  |\n");
    printf("      |\\\n");
    printf("---------      %s\n", findWord);
    break;
  case 9:
    printf("\n  -----        %s                         Lettre: %d\n", findWord, tryCharacter);
    printf("  |  \\|                                        mot: %d\n", tryWord);
    printf("  0   |\n");
    printf(" /|\\  |\n");
    printf(" / \\  |\n");
    printf("      |\\\n");
    printf("---------      %s\n", findWord);
    printf("GAME OVER\n");
    break;
  default:
    printf("\n  -----        %s                         Lettre: %d\n", findWord, tryCharacter);
    printf("  |   |                                        mot: %d\n", tryWord);
    printf("      |\n");
    printf("      |\n");
    printf("      |\n");
    printf("      |\n");
    printf("--------       %s\n", findWord);
    break;
  }
}