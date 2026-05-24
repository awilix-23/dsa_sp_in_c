#ifndef LIST_INTERFACE_H_
#define LIST_INTERFACE_H_

#include "ListTypes.h"

extern void Initialize(List *L);
extern int Empty(List *L);
extern int Length(List *L);
extern ItemType Select(int index, List *L);
extern void Replace(int index, ItemType X, List *L);
extern void Insert(int index, ItemType X, List *L);
extern void Delete(ItemType X, List *L);

#endif /* LIST_INTERFACE_H_ */
