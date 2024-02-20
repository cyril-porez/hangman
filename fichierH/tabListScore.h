#ifndef TABLISTSCORE_H

#define TABLISTSCORE_H
#define MAXNOM 20

typedef struct
{
  char name[MAXNOM];
  int score;
  char difficulty[10];
} Score;

typedef struct
{
  Score *easy;
  int sizeEasy;
  Score *middle;
  int sizeMiddle;
  Score *hard;
  int sizeHard;
} ScoreBoard;


#endif