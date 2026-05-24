#include <stdlib.h>
#include <stdio.h>
#include "../PQInterface.h"

void Initialize(PriorityQueue *PQ)
{
  PQ->ItemList = NULL;
}

int Empty(PriorityQueue *PQ)
{
  return (PQ->ItemList == NULL);
}

int Full(PriorityQueue *PQ)
{
  return 0;
}

void Insert(ItemType X, PriorityQueue *PQ)
{
  QueueNode *Tmp;
  Tmp = (QueueNode *)malloc(sizeof(QueueNode));

  if (Tmp == NULL) {
    fprintf(stderr, "System memory exceeded.\n");
  } else {
    Tmp->Link = PQ->ItemList;
    Tmp->Item = X;
    PQ->ItemList = Tmp;
  }
}

void Remove(ItemType *X, PriorityQueue *PQ)
{
  QueueNode *Tmp;

  if (PQ->ItemList == NULL) {
    fprintf(stderr, "Attempt to remove item from an empty queue.\n");
  } else {
    Tmp = PQ->ItemList;
    *X = Tmp->Item;
    PQ->ItemList = Tmp->Link;
    free(Tmp);
  }
}
