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
  printf("메인함수 return까지 도착\n");
  return 0;
}
