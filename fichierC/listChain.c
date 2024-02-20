#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../fichierH/listChain.h"

Node *createNode(const char *data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Erreur allocation mémoire");
        exit(1);
    }
    newNode->data = strdup(data);
    newNode->next = NULL;
    return newNode;
}

void push(Node **headRef, const char *str)
{
    Node *newNode = createNode(str);
    newNode->next = *headRef;
    *headRef = newNode;
}

void displayListChain(Node *node)
{
    while (node != NULL)
    {
        printf("%s -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int getListSize(Node *listChain)
{
    int size = 0;
    while (listChain != NULL)
    {
        size++;
        listChain = listChain->next;
    }
    return size;
}

char *getRandomElement(Node *chainList)
{
    int size = getListSize(chainList);
    if (size == 0)
    {
        return NULL;
    }
    srand(time(NULL));
    int searchValueRandom = rand() % size;

    for (int i = 0; i < searchValueRandom; i++)
    {
        chainList = chainList->next;
    }
    return chainList->data;
}
