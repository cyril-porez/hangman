#ifndef LISTCHAIN_H
#define LISTCHAIN_H

typedef struct Node
{
  char *data;
  struct Node *next;
} Node;

Node *createNode(const char *data);
void push(Node **headRef, const char *str);
void displayListChain(Node *node);
int getListSize(Node *listChain);
char *getRandomElement(Node *chainList);
void freeNode(Node *node);
void freeChain(Node *head);

#endif