#include <stdio.h>
#include "../StackInterface.h"

void Initialize(Stack *S)
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

void Push(ItemType X, Stack *S)
{
  if (S->Count == MAXSTACKSIZE) {
    fprintf(stderr, "Attempt to push to full stack.\n");
  } else {
    S->Items[S->Count] = X;
    ++(S->Count);
  }
}

void Pop(ItemType *X, Stack *S)
{
  if (S->Count == 0) {
    fprintf(stderr, "Attempt to pop from an empty stack.\n");
  } else {
    --(S->Count);
    *X = S->Items[S->Count];
  }
}
