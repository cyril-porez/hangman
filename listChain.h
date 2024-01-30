#ifndef LISTCHAIN_H
#define LISTCHAIN_H

typedef struct Node {
  char *data;
  struct Node *next;
}Node;

Node* createNode(const char *data);
void push(Node **headRef, const char *str);
void displayListChain(Node *node);
char *getRandomElement(Node *chainList);


#endif