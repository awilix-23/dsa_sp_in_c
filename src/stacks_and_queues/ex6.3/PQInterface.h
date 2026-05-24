#ifndef PQINTERFACE_H_
#define PQINTERFACE_H_

#include "linked/PQTypes.h"

extern void Initialize(PriorityQueue *);
extern int Empty(PriorityQueue *);
extern int Full(PriorityQueue *);
extern void Insert(ItemType, PriorityQueue *);
extern void Remove(ItemType *, PriorityQueue *);

#endif /* PQINTERFACE_H_ */
