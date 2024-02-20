#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabListScore.h"

void addScore(ScoreBoard *sb, const char *nom, int score, const char *difficulty)
{
  Score s;
  strncpy(s.name, nom, MAXNOM);
  s.score = score;
  strncpy(s.difficulty, difficulty, 10);

  if (strcmp(difficulty, "facile") == 0)
  {
    sb->easy = realloc(sb->easy, (sb->sizeEasy + 1) * sizeof(Score));
    sb->easy[sb->sizeEasy++] = s;
  }
  else if (strcmp(difficulty, "moyen") == 0)
  {
    sb->middle = realloc(sb->middle, (sb->sizeMiddle + 1) * sizeof(Score));
    sb->middle[sb->sizeMiddle++] = s;
  }
  else if (strcmp(difficulty, "difficile") == 0)
  {
    sb->hard = realloc(sb->hard, (sb->sizeHard + 1) * sizeof(Score));
    sb->hard[sb->sizeHard++] = s;
  }
  else
  {
    printf("Niveau de difficulté incorect!");
  }
}

void displayScore(FILE *file, Score *scores, int size)
{
  for (int i = 0; i < size; i++)
  {
    fprintf(file, "\n%s      %d      %s", scores[i].name, scores[i].score, scores[i].difficulty);
  }
}

int compareScore(const void *a, const void *b)
{
  const Score *scoreA = (const Score *)a;
  const Score *scoreB = (const Score *)b;
  return scoreA->score - scoreB->score;
}