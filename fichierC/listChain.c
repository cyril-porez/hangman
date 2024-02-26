#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../fichierH/listChain.h"
#include <ncurses.h>

Node *createNode(const char *data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printw("Erreur allocation mémoire");
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
        node = node->next;
    }
    printw("NULL\n");
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

void freeNode(Node *node)
{
    if (node != NULL)
    {
        free(node->data);
        free(node);
    }
}

void freeChain(Node *head)
{
    Node *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        freeNode(tmp);
    }
}
