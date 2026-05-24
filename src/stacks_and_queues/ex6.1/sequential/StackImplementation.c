#include <stdio.h>
#include "../StackInterface.h"

void InitializeStack (Stack *S)
{
  S->Count = 0;
}

int Empty(Stack *S)
{
  return (S->Count == 0);
}

int Full(Stack *S)
{
  return (S->Count == MAXSTACKSIZE);
}

void Push(Stack *S, ItemType X)
{
  if (S->Count == MAXSTACKSIZE) {
    fprintf(stderr, "Attempt to push new item into a full stack.\n");
  } else {
    S->Items[S->Count] = X;
    ++(S->Count);
  }
}

void Pop(Stack *S, ItemType *X)
{
  if (S->Count == 0) {
    fprintf(stderr, "Attempt to pop an empty stack.\n");
  } else {
    --(S->Count);
    *X = S->Items[S->Count];
  }
}
