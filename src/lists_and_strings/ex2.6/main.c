#include <assert.h>
#include "ListInterface.h"

int main(void)
{
  List L;

  Initialize(&L);
  assert(Length(&L) == 0);

  Insert(1, 1.0, &L);
  assert(Length(&L) == 1);
  assert(Select(1, &L) == 1.0);

  Insert(2, 2.0, &L);
  assert(Select(2, &L) == 2.0);

  Replace(1, 3.0, &L);
  assert(Select(1, &L) == 3.0);

  Delete(3.0, &L);
  assert(Length(&L) == 1);
  assert(Select(1, &L) == 2.0);

  return 0;
}
