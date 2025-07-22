#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../lib/ch02.h"
/******************************************************************************/
void Partition(NodeType *L, NodeType **Head, NodeType **Tail);
NodeType *Concat(NodeType *L1, NodeType *L2);
NodeType *Reverse(NodeType *L);

double Power_Down(double x, unsigned int n);
double Power_Half(double x, unsigned int n);
int Mult(unsigned int m, unsigned int n);
int GCD(unsigned int m, unsigned int n);
int Product_Up(int m, int n);
char *ReverseString(char *S);
char *ReverseStr(char *S, char *R);
   
int ListLength(NodeType *L);
int Min(int *A, int length);
int Ackermann(int m, int n);

double Sqrt(double x);
int Choose(int n, int k);
/******************************************************************************/
int main()
{
  printf("4 choose 2: %d\n", Choose(4, 2));
  return 0;
}
/******************************************************************************/
void Partition(NodeType *L, NodeType **Head, NodeType **Tail)
{
  if (L != NULL) {
    *Tail = L->Link;
    *Head = L;
    (*Head)->Link = NULL;
  }
}

NodeType *Concat(NodeType *L1, NodeType *L2)
{
  NodeType *N;

  if (L1 == NULL) {
    return L2;
  } else {
    N = L1;
    while (N->Link != NULL) N = N->Link;
    N->Link = L2;
    return L1;
  }
}

NodeType *Reverse(NodeType *L)
{
  NodeType *Head, *Tail;

  if (L == NULL) {
    return NULL;
  } else {
    Partition(L, &Head, &Tail);
    return Concat(Reverse(Tail), Head);
  }
}
/******************************************************************************/
/* My solutions */

/* Exercise 3.2.1 */
double Power_Down(double x, unsigned int n)
{
  if (n == 0) {
    return 1.0;
  } else {
    return x * Power_Down(x, n - 1);
  }
}

/* Exercise 3.2.2 */
double Power_Half(double x, unsigned int n)
{
  unsigned int middle;
  if (n == 0) {
    return 1.0;
  } else {
    middle = n / 2;
    if (n % 2 != 0) {
      return x * Power_Half(x, middle) * Power_Half(x, middle);
    } else {
      return Power_Half(x, middle) * Power_Half(x, middle);
    }
  }
}

/* Exercise 3.2.3 */
int Mult(unsigned int m, unsigned int n)
{
  if ((m == 0) || (n == 0)) {
    return 0;
  } else {
    return m + Mult(m, n - 1);
  }
}

/* Exercise 3.2.4 */
int GCD(unsigned int m, unsigned int n)
{
  if (n == 0) {
    return 0;
  }
  unsigned int r = m % n;
  if (r == 0) {
    return n;
  } else {
    return GCD(n, r);
  }
}

/* Exercise 3.2.6 */
int Product_Up(int m, int n)
{
  if (m == n) {
    return n;
  } else {
    return m * Product_Up(m + 1, n);
  }
}

/* Exercise 3.2.7 */
void PartitionString(char *S, char *Head, char **Tail)
{
  if (strcmp(S, "") != 0) {
    *Tail = &S[1];
    *Head = S[0];
  }
}

char *ConcatString(char *Tail, char Head)
{

  if (strcmp(Tail, "") == 0) {
    char *C = malloc(2);
    C[0] = Head;
    C[1] = '\0';
    return C;
  } else {
    char *C;
    C = Tail;
    while (*C != '\0') C++;
    *C++ = Head;
    return Tail;
  }
}

char *ReverseString(char *S)
{
  char Head, *Tail;

  if (strcmp(S, "") == 0) {
    return S;
  } else {
    PartitionString(S, &Head, &Tail);
    return ConcatString(ReverseString(Tail), Head);
  }
}

/* Exercise 3.2.8 */
char *ReverseStr(char *S, char *R)
{
  if (strcmp(S, "") == 0) {
    return S;
  } else {
    char Head = S[0];
    S++;
    return ConcatString(ReverseStr(S, R), Head);
  }
}

/* Exercise 3.2.9 */
int ListLength(NodeType *L)
{
  if (L == NULL) {
    return 0;
  } else {
    return 1 + ListLength(L->Link);
  }
}

/* Exercise 3.2.10 */
int Min2(int *A, int start, int end)
{
  if (start == end) {
    return A[start];
  } else if (A[start] < A[end]) {
    return Min2(A, start, end - 1);
  } else {
    return Min2(A, start + 1, end);
  }
}

int Min(int *A, int length)
{
  if (length == 1) {
    return A[0];
  } else {
    return Min2(A, 0, length - 1);
  }
}

/* Exercise 3.2.11 */
int Ackermann(int m, int n)
{
  if (n >= 0 && m == 0) {
    return n + 1;
  } else if (m > 0 && n == 0) {
    return Ackermann(m - 1, 1);
  } else if (m > 0 && n > 0) {
    return Ackermann(m - 1, Ackermann(m, n - 1));
  } else {
    printf("Error ! Invalid m or n value\n");
    return 0;
  }
}
/* Exercise 3.2.15 */
double Sqrt1(double x, double a)
{
  a = (a + (x / a)) / 2;
  if (fabs((a * a) - x) <= 1) {
    return a;
  } else {
    return Sqrt1(x, a);
  }
}
double Sqrt(double x)
{
  double a = x / 2;

  if (fabs((a * a) - x) <= 1) {
    return a;
  } else {
    return Sqrt1(x, a);
  }
}

/* Exercise 3.2.16 */
/* Return later to eliminate wasteful calculations */
int Choose(int n, int k)
{
  if (k == n || k == 0) {
    return 1;
  } else {
    return Choose(n - 1, k) + Choose(n - 1, k - 1);
  }
}
