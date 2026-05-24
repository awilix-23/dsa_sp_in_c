#include <stdio.h>
#include <stdlib.h>
#include "../StackInterface.h"

void InitializeStack(Stack *S)
{
  S->ItemList = NULL;
}

int Empty(Stack *S)
{
  return (S->ItemList == NULL);
}

int Full(Stack *S)
{
  return 0;
}

void Push(Stack *S, ItemType X)
{
  StackNode *Temp;
  Temp = (StackNode *)malloc(sizeof(StackNode));

  if (Temp == NULL) {
    fprintf(stderr, "System storage exhausted.\n");
  } else {
    Temp->Link = S->ItemList;
    Temp->Item = X;
    S->ItemList = Temp;
  }
}

void Pop(Stack *S, ItemType *X)
{
  StackNode *Temp;

  if (S->ItemList == NULL) {
    fprintf(stderr, "Attempt to pop an empty stack.\n");
  } else {
    Temp = S->ItemList;
    *X = Temp->Item;
    S->ItemList = Temp->Link;
    free(Temp);
  }
}
