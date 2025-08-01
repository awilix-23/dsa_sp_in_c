#include <stdio.h>
#include "PQInterface.h"
/******************************************************************************/
void Initialize(PriorityQueue *PQ)
{
  PQ->Count = 0;
  PQ->ItemList = NULL;
}

int Empty(PriorityQueue *PQ)
{
  return (PQ->Count == 0);
}

int Full(PriorityQueue *PQ)
{
  return (PQ->Count == MAXCOUNT);
}

PQListNode *SortedInsert(PQItem Item, PQListNode *P)
{
  PQListNode *N;

  if (P == NULL) || (Item >= P->NodeItem) {
    N = (PQListNode *)malloc(sizeof(PQListNode));
    N->NodeItem = Item;
    N->Link = P;
    return (N);
  } else {
    P->Link = SortedInsert(Item, P->Link);
    return (P);
  }
}

void Insert(PQItem Item, PriorityQueue *PQ)
{
  if (!Full(PQ)) {
    PQ->Count++;
    PQ->ItemList = SortedInsert(Item, PQ->ItemList);
  }
}

PQItem Remove(PriorityQueue *);
