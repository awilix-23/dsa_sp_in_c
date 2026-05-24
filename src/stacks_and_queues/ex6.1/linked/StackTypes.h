#ifndef STACK_TYPES_H_
#define STACK_TYPES_H_

typedef float ItemType;

typedef struct StackNodeTag {
  ItemType Item;
  struct StackNodeTag *Link;
} StackNode;

typedef struct {
  StackNode *ItemList;
} Stack;

#endif /* STACK_TYPES_H_ */
