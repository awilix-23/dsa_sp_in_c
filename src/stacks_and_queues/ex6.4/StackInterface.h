#ifndef STACK_H_
#define STACK_H_

#include "sequential/StackTypes.h"

extern void Initialize(Stack *);
extern int Empty(Stack *);
extern int Full(Stack *);
extern void Push(ItemType, Stack *);
extern void Pop(ItemType *, Stack *);

#endif /* STACK_H_ */
