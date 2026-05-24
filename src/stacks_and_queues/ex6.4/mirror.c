#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "StackInterface.h"

int main(int argc, char **argv)
{
  if (argc != 2) {
    fprintf(stderr, "1 input string required.\n");
    return 1;
  }
  char *T = argv[1];

  Stack *S;
  S = (Stack *)malloc(sizeof(Stack));
  Initialize(S);

  char c;
  bool lhs_done;
  ItemType X, Y;

  for (int i = 0; i <= (int)strlen(T) - 1; i++) {
    X = c = T[i];

    if (c != 'a' && c != 'b' && c != 'c' && c != 'm') {
      fprintf(stderr, "Invalid character encountered: %c\n", c);
      break;
    }

    /* No check for missing or duplicate 'm' :c */
    if (c == 'm') { lhs_done = true; continue; }

    if (!lhs_done) {
      Push(X, S);
    } else {
      Pop(&Y, S);
      if (X != Y) {
        fprintf(stderr, "Right operand is not a mirrored left operand.\n");
        break;
      }
    }
  }

  free(S);

  return 0;
}
