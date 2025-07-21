#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/ch02.h"
/******************************************************************************/
void InsertNewFirstNode(char *A, NodeType **L);
void DeleteFirstNode(NodeType **L);
void InsertNodeBefore(char *A, char *B, NodeType **L);
NodeType *Copy(NodeType **L);
void Reverse(NodeType **L);
NodeType *FindNode(char *A, NodeType *L);
NodeType *Concat(NodeType *L1, NodeType *L2);
/******************************************************************************/
int main(void)
{
  NodeType *L, *M, *N;
  L = M = NULL;

  /* Initialize List */
  InsertNewLastNode("ARN", &L);
  InsertNewLastNode("BRU", &L);

  InsertNewLastNode("JFK", &M);
  InsertNewLastNode("SAN", &M);
  InsertNewLastNode("HKG", &M);

  /* Manipulating List */
  PrintList(L);
  PrintList(M);
  printf("---------------\n");
  N = Concat(L, M);
  PrintList(N);

  return 0;
}
/******************************************************************************/
/* My solutions */

/* Exercise 2.5.1 */
void InsertNewFirstNode(char *A, NodeType **L)
{
  NodeType *N;
  N = (NodeType *)malloc(sizeof(NodeType));

  strcpy(N->Airport, A);
  N->Link = *L;
  *L = N;
}

/* Exercise 2.5.2 */
void DeleteFirstNode(NodeType **L)
{
  NodeType *FirstNode;
  if (*L != NULL) {
    if ((*L)->Link == NULL) {
      free(*L);
      *L = NULL;
    } else {
      FirstNode = *L;
      *L = (*L)->Link;
      free(FirstNode);
    }
  }
}

/* Exercise 2.5.3 */
void InsertNodeBefore(char *A, char *B, NodeType **L)
{
  NodeType *N, *M;
  N = (NodeType *)malloc(sizeof(NodeType));
  N = *L;

  M = (NodeType *)malloc(sizeof(NodeType));
  M->Link = NULL;

   while (strcmp(N->Airport, B) != 0) {
     N = N->Link;
   }

   M->Link = N->Link;
   N->Link = M;

   strcpy(M->Airport, N->Airport);
   strcpy(N->Airport, A);
}

/* Exercise 2.5.4 */
NodeType *Copy(NodeType **L)
{
  NodeType *N, *M;
  N = (NodeType *)malloc(sizeof(NodeType));
  N = *L;

  M = NULL;
 
  while (N != NULL) {
    InsertNewLastNode(N->Airport, &M);
    N = N->Link;
  }
  
  return M;
}

/* Exercise 2.5.5 */
void Reverse(NodeType **L)
{
  NodeType *N, *L2;
  N = (NodeType *)malloc(sizeof(NodeType));
  N = *L;

  L2 = NULL;

  while (N != NULL) {
    InsertNewFirstNode(N->Airport, &L2);
    N = N->Link;
    DeleteFirstNode(L);
  }

  *L = Copy(&L2);
}

/* Exercise 2.5.6 */
NodeType *FindNode(char *A, NodeType *L)
{
  while ( (L != NULL) && (strcmp(L->Airport, A) != 0) ) {
    L = L->Link;
  }
  return L;
}

/* Exercise 2.5.7 */
NodeType *Concat(NodeType *L1, NodeType *L2)
{
  NodeType *N;
  N = Copy(&L1);
  while (L2 != NULL) {
    InsertNewLastNode(L2->Airport, &N);
    L2 = L2->Link;
  }
  return N;
}

/* Exercise 2.5.8 */
NodeType *LastNode(NodeType *L)
{
  if (L != NULL) {
    do {
      L = L->Link;
    } while (L->Link != NULL);
  }
  return L;
}
