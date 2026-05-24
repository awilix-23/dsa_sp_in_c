#ifndef STACK_TYPES_H_
#define STACK_TYPES_H_

#define MAXSTACKSIZE 100

typedef float ItemType;

typedef struct {
  int Count;
  ItemType Items[MAXSTACKSIZE];
} Stack;

#endif /* STACK_TYPES_H_ */
