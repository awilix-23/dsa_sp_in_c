#ifndef QUEUE_INTERFACE_H_
#define QUEUE_INTERFACE_H_

#include "QueueTypes.h"

extern void InitializeQueue(Queue *S);
extern int Empty(Queue *S);
extern int Full(Queue *S);
extern void Insert(Queue *S, ItemType *X);
extern void Remove(Queue *S, ItemType *X);

#endif /* QUEUE_INTERFACE_H_ */
