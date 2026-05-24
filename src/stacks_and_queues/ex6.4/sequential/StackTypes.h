#ifndef TYPES_H_
#define TYPES_H_

#define MAXSTACKSIZE 100

typedef char ItemType;

typedef struct {
  int Count;
  ItemType Items[MAXSTACKSIZE];
} Stack;

#endif /* TYPES_H_ */
