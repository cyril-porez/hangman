#include <stdio.h>
#include <ncurses.h>

void potence(char *findWord, char *categoryWord, int error, int tryWord, int tryCharacter)
{
  switch (error)
  {
  case 1:
    clear();
    move(0, 0);
    printw("\n  -----        %s                         Lettre: %d\n", categoryWord, tryCharacter);
    printw("  |   |                                        mot: %d\n", tryWord);
    printw("  0   |\n");
    printw("      |\n");
    printw("      |\n");
    printw("      |\n");
    printw("--------       %s\n", findWord);
    refresh();
    break;
  case 2:
    clear();
    move(0, 0);
    printw("\n  -----        %s                         Lettre: %d\n", categoryWord, tryCharacter);
    printw("  |   |                                        mot: %d\n", tryWord);
    printw("  0   |\n");
    printw(" /    |\n");
    printw("      |\n");
    printw("      |\n");
    printw("--------       %s\n", findWord);
    refresh();
    break;
  case 3:
    clear();
    move(0, 0);
    printw("\n  -----        %s                         Lettre: %d\n", categoryWord, tryCharacter);
    printw("  |   |                                        mot: %d\n", tryWord);
    printw("  0   |\n");
    printw(" /|   |\n");
    printw("      |\n");
    printw("      |\n");
    printw("---------      %s\n", findWord);
    refresh();
    break;
  case 4:
    clear();
    move(0, 0);
    printw("\n  -----        %s                         Lettre: %d\n", categoryWord, tryCharacter);
    printw("  |   |                                        mot: %d\n", tryWord);
    printw("  0   |\n");
    printw(" /|\\  |\n");
    printw("      |\n");
    printw("      |\n");
    printw("---------      %s\n", findWord);
    refresh();
    break;
  case 5:
    clear();
    move(0, 0);
    printw("\n  -----        %s                         Lettre: %d\n", categoryWord, tryCharacter);
    printw("  |   |                                        mot: %d\n", tryWord);
    printw("  0   |\n");
    printw(" /|\\  |\n");
    printw(" /    |\n");
    printw("      |\n");
    printw("--------       %s\n", findWord);
    refresh();
    break;
  case 6:
    clear();
    move(0, 0);
    printw("\n  -----        %s                         Lettre: %d\n", categoryWord, tryCharacter);
    printw("  |   |                                        mot: %d\n", tryWord);
    printw("  0   |\n");
    printw(" /|\\  |\n");
    printw(" / \\  |\n");
    printw("      |\n");
    printw("--------       %s\n", findWord);
    refresh();
    break;
  case 7:
    clear();
    move(0, 0);
    printw("\n  -----        %s                         Lettre: %d\n", categoryWord, tryCharacter);
    printw("  |  \\|                                        mot: %d\n", tryWord);
    printw("  0   |\n");
    printw(" /|\\  |\n");
    printw(" / \\  |\n");
    printw("      |\n");
    printw("--------       %s\n", findWord);
    refresh();
    break;
  case 8:
    clear();
    move(0, 0);
    printw("\n  -----        %s                         Lettre: %d\n", categoryWord, tryCharacter);
    printw("  |  \\|                                        mot: %d\n", tryWord);
    printw("  0   |\n");
    printw(" /|\\  |\n");
    printw(" / \\  |\n");
    printw("      |\\\n");
    printw("---------      %s\n", findWord);
    refresh();
    break;
  case 9:
    clear();
    move(0, 0);
    printw("\n  -----        %s                         Lettre: %d\n", categoryWord, tryCharacter);
    printw("  |  \\|                                        mot: %d\n", tryWord);
    printw("  0   |\n");
    printw(" /|\\  |\n");
    printw(" / \\  |\n");
    printw("      |\\\n");
    printw("---------      %s\n", findWord);
    printw("GAME OVER\n");
    refresh();
    break;
  default:
    printw("\n  -----        %s                         Lettre: %d\n", categoryWord, tryCharacter);
    printw("  |   |                                        mot: %d\n", tryWord);
    printw("      |\n");
    printw("      |\n");
    printw("      |\n");
    printw("      |\n");
    printw("--------       %s\n", findWord);
    refresh();
    break;
  }
}