#ifndef STACK_INTERFACE_H_
#define STACK_INTERFACE_H_

// #include "sequential/StackTypes.h"
#include "linked/StackTypes.h"

extern void InitializeStack(Stack *S);
extern int Empty(Stack *S);
extern int Full(Stack *S);
extern void Push(Stack *S, ItemType X);
extern void Pop(Stack *S, ItemType *X);

#endif /* STACK_INTERFACE_H_ */
