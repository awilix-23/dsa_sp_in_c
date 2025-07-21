#ifndef CH02_H_
#define CH02_H_

typedef char AirportCode[4];
typedef struct NodeTag {
  AirportCode Airport;
  struct NodeTag *Link;
} NodeType;

void PrintList(NodeType *L);
void InsertNewLastNode(char *A, NodeType **L);
void DeleteLastNode(NodeType **L);
NodeType *ListSearch(char *A, NodeType *L);
void InsertNewSecondNode(NodeType **L);

#endif // CH02_H_
