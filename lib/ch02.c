#include "ch02.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertNewSecondNode(NodeType **L)
{
  NodeType *N;
  N = (NodeType *)malloc(sizeof(NodeType));

  strcpy(N->Airport, "BRU");
  N->Link = (*L)->Link;
  (*L)->Link = N;
}

NodeType *ListSearch(char *A, NodeType *L)
{
  NodeType *N;
  N = L;

  while (N != NULL) {
    if (strcmp(N->Airport, A) == 0) {
      return N;
    } else {
      N = N->Link;
    }
  }
  return N;
}

void DeleteLastNode(NodeType **L)
{
  NodeType *PreviousNode, *CurrentNode;

  if (*L != NULL) {
    if ((*L)->Link == NULL) {
      free(*L);
      *L = NULL;
    } else {
      PreviousNode = *L;
      CurrentNode = (*L)->Link;

      while (CurrentNode->Link != NULL) {
        PreviousNode = CurrentNode;
        CurrentNode = CurrentNode->Link;
      }

      PreviousNode->Link = NULL;
      free(CurrentNode);
    }
  }
}

void InsertNewLastNode(char *A, NodeType **L)
{
  NodeType *N, *P;

  N = (NodeType *)malloc(sizeof(NodeType));
  strcpy(N->Airport, A);
  N->Link = NULL;

  if (*L == NULL) {
    *L = N;
  } else {
    P = *L;
    while (P->Link != NULL) P = P->Link;
    P->Link = N;
  }
}

void PrintList(NodeType *L)
{
  NodeType *N;
  N = L;

  printf("(");

  while (N != NULL) {
    printf("%s", N->Airport);
    N = N->Link;
    if (N != NULL) printf(", ");
  }
  
  printf(")\n");
}
