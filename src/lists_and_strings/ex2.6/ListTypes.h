#ifndef LIST_TYPES_H_
#define LIST_TYPES_H_

typedef float ItemType;

typedef struct ListNodeTag {
  ItemType Item;
  struct ListNodeTag *Link;
} ListNode;

typedef struct {
  int Count;
  ListNode *Header;
} List;

#endif /* LIST_TYPES_H_ */
