#include <assert.h>
#include <stdio.h>
#include <time.h>
#include "PQInterface.h"

int main(void)
{
  PriorityQueue PQ;
  ItemType T, S;

  Initialize(&PQ);

  T = clock();
  Insert(T, &PQ);

  S = clock();
  Insert(S, &PQ);

  Remove(&S, &PQ);
  Remove(&T, &PQ);

  assert(S > T);

  printf("Node S: %.0f\n", S);
  printf("Node T: %.0f\n", T);

  return 0;
}
