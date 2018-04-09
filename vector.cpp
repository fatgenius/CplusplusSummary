#include "vector.h"

int main ()
{
  vector<int> vInts; 
  vInts.assign(10, 5);
  printVector(vInts);
  assignFunction(vInts, 1);
  pushBackFunction(vInts, 2);
  emplaceFunction(vInts,1, 3);

  return 0;
}
