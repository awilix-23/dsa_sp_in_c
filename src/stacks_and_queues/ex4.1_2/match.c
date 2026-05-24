#include <string.h>
#include <stdio.h>
#include "StackInterface.h"

int Match(char, char);


int main(int argc, char **argv)
{
  if (argc != 2) {
    fprintf(stderr, "One input string, please.\n");
    return 1;
  }

  char *InputExpression = argv[1];

  int i = 0;
  char c,d;
  Stack ParenStack;

  Initialize(&ParenStack);

  while (i < (int)strlen(InputExpression)) {
    d = InputExpression[i];

    if (d == '(' || d == '[' || d == '{') {
      if (Full(&ParenStack)) {
        fprintf(stderr, "Stack overflow ! Results inconclusive.\n");
        return 1;
      } else {
        Push(d, &ParenStack);
      }
    } else if (d == ')' || d == ']' || d == '}') {
      if (Empty(&ParenStack)) {
        fprintf(stderr, "Too many right parantheses.\n");
        return 1;
      } else {
        Pop(&c, &ParenStack);
        if (!Match(c, d)) {
          fprintf(stderr, "Mismatched parentheses: %c and %c.\n", c, d);
          return 1;
        }
      }
    }

    ++i;
  }

  if (!Empty(&ParenStack)) {
    fprintf(stderr, "Too many left parantheses.\n");
    return 1;
  }

  return 0;
}

int Match(char c, char d)
{
  switch (c) {
    case '(':
      return (d == ')');
      break;
    case '[':
      return (d == ']');
      break;
    case '{':
      return (d == '}');
      break;
    default:
      return 0;
      break;
  }
}
