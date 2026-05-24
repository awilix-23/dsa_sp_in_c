#ifndef PQTYPES_H_
#define PQTYPES_H_

typedef float ItemType;

typedef struct QueueNodeTag {
  ItemType Item;
  struct QueueNodeTag *Link;
} QueueNode;

typedef struct {
  QueueNode *ItemList;
} PriorityQueue;

#endif /* PQTYPES_H_ */
