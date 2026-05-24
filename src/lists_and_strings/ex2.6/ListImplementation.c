#include <stdlib.h>
#include <stdio.h>
#include "ListInterface.h"

#define SENTINAL_VALUE 99999.9

void Initialize(List *L)
{
  L->Header = (ListNode *)malloc(sizeof(ListNode));
  L->Header->Link = NULL;
  L->Count = 0;
}

int Empty(List *L)
{
  return (L->Count == 0);
}

int Length(List *L)
{
  return (L->Count);
}

ItemType Select(int index, List *L)
{
  if (L->Count == 0) {
    fprintf(stderr, "List is empty.\n");
    return SENTINAL_VALUE;
  }

  ItemType SelectedItem;
  ListNode *M;
  M = L->Header;

  for (int i = 1; i <= index; i++) { M = M->Link; }

  SelectedItem = M->Item;

  return SelectedItem;
}

void Replace(int index, ItemType X, List *L)
{
  if (L->Count == 0) {
    fprintf(stderr, "List is empty.\n");
    return;
  }

  ListNode *M;
  M = L->Header;

  for (int i = 1; i <= index; i++) { M = M->Link; }

  M->Item = X;
}

void Insert(int index, ItemType X, List *L)
{
  ListNode *N;
  N = (ListNode *)malloc(sizeof(ListNode));

  if (L->Count == 0) {
    L->Header->Link = N;
    N->Item = X;
    N->Link = NULL;
    L->Count++;
  } else {
    ListNode *M;
    M = L->Header;

    for (int i = 1; i < index; i++) { M = M->Link; }

    N->Link = M->Link;
    M->Link = N;
    N->Item = X;

    if (L->Count == 1) {
      while (M->Link != NULL) { M = M->Link; }
      M->Link = L->Header->Link;
    }

    L->Count++;
  }
}

void Delete(ItemType X, List *L)
{
  if (L->Count == 0) {
    fprintf(stderr, "List is empty.\n");
    return;
  }

  ListNode *N, *M;
  M = L->Header->Link;

  if (M->Item == X) {
    L->Header->Link = M->Link;
    free(M);
    L->Count--;
    return;
  }

  while (M->Link != NULL && M->Link->Item != X) { 
    M = M->Link;
    if (M == L->Header->Link) {
      fprintf(stderr, "Item not found in list.\n");
      return;
    }
  }

  N = M->Link;

  if (L->Count <= 2) {
    M->Link = NULL;
  } else {
    M->Link = N->Link;
  }

  free(N);
  L->Count--;
}
