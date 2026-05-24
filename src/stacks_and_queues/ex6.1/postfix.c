#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "StackInterface.h"


int main(int argc, char **argv)
{
  if (argc < 2) {
    fprintf(stderr, "Postfix string required");
  }

  Stack EvalStack;
  char *PostfixString = argv[1];

  float LeftOperand, RightOperand, Result;
  int i;
  char c;
  char s[2] = "x";

  InitializeStack(&EvalStack);

  for (i = 0; i < (int)strlen(PostfixString); ++i) {
    c = PostfixString[i];
    s[0] = c;

    if (isdigit(c)) {
      Push(&EvalStack, (float)atof(s));
    } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
      Pop(&EvalStack, &RightOperand);
      Pop(&EvalStack, &LeftOperand);

      switch (c) {
        case '+':
          Push(&EvalStack, LeftOperand + RightOperand);
          break;
        case '-':
          Push(&EvalStack, LeftOperand - RightOperand);
          break;
        case '*':
          Push(&EvalStack, LeftOperand * RightOperand);
          break;
        case '/':
          Push(&EvalStack, LeftOperand / RightOperand);
          break;
        case '^':
          Push(&EvalStack, exp(log(LeftOperand) * RightOperand));
          break;
        default:
          break;
      }
    }
  }

  Pop(&EvalStack, &Result);
  printf("Postfix value = %f\n", Result);

  return 0;
}
