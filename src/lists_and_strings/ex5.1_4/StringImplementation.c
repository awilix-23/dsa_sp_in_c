#include <stdlib.h>
#include "StringInterface.h"

int StringLen(char *S)
{
  int length = 0;

  while (S[length] != '\0') { length++; }

  return length;
}

char *StringStr(char *S, char *T)
{
  for (int i = 0; T[i] != '\0'; i++) {
    if (T[i] != S[0]) { continue; }

    int j;
    for (j = 0; S[j] != '\0'; j++) {
      if (T[i + j] != S[j]) { break; }
    }

    if (S[j] == '\0') {
      return &T[i];
    }
  }

  return NULL;
}

void StringCpy(char *S, char *T)
{
  while ((*S++ = *T++) != '\0');
}

int StringSpn(char *S, char *T)
{
  int length;

  for (length = 0; S[length] != '\0'; length++) {
    int found = 0;

    for (int i = 0; T[i] != '\0'; i++) {
      if (S[length] == T[i]) { found = 1; }
    }

    if (!found) { return length; }
  }

  return length;
}
