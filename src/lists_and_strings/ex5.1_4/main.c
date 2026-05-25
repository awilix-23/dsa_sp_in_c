#include <assert.h>
#include <string.h>
#include "StringInterface.h"

int main(void)
{
  char *S = "bar";
  char *T = "foobarbaz";
  char Q[10];
  char *R = "fob";

  assert(StringLen(S) == 3);

  assert(strcmp(StringStr(S,T), "barbaz") == 0);

  StringCpy(Q,S);
  assert(strcmp(Q, "bar") == 0);

  assert(StringSpn(T,R) == 4);

  return 0;
}
