#include "common.h"
#include "function.h"

int main(void) {

  int endOrNot = ING;
  showProblem();
  NodeInit();

  while(endOrNot == ING) {
    endOrNot = moving();
  }

  showResult(endOrNot);
  return 0;
}
