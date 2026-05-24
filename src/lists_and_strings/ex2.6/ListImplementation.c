#include <stdlib.h>
#include <stdio.h>
#include "ListInterface.h"

#define SENTINEL_VALUE 99999.9

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
    return SENTINEL_VALUE;
  }
  if (index < 1 || index > L->Count) {
    fprintf(stderr, "Invalid index.\n");
    return SENTINEL_VALUE;
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
  if (index < 1 || index > L->Count) {
    fprintf(stderr, "Invalid index.\n");
    return;
  }

  ListNode *M;
  M = L->Header;

  for (int i = 1; i <= index; i++) { M = M->Link; }

  M->Item = X;
}

void Insert(int index, ItemType X, List *L)
{
  if (index < 1 || index > L->Count + 1) {
    fprintf(stderr, "Invalid index.\n");
    return;
  }

  ListNode *N, *M;
  N = (ListNode *)malloc(sizeof(ListNode));

  M = L->Header;
  for (int i = 1; i < index; i++) { M = M->Link; }

  N->Item = X;
  N->Link = (L->Count == 0) ? N : M->Link;
  M->Link = N;

  L->Count++;
}

void Delete(ItemType X, List *L)
{
  if (L->Count == 0) {
    fprintf(stderr, "List is empty.\n");
    return;
  }

  ListNode *N, *M;
  M = L->Header;

  do {
    if (M->Link->Item == X) {
      N = M->Link;
      M->Link = N->Link;
      free(N);
      L->Count--;

      if (L->Count == 0) { L->Header->Link = NULL; }
    } else {
      M = M->Link;
    }
  } while(M != L->Header && M->Link != L->Header->Link);
}
