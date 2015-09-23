#include "common.h"
#include "function.h"

int mazeBoard[ROW_LEN][COL_LEN] = {
	{0, 0, 0, 1, 1, 0, 1, 1, 1, 1},
	{1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 1, 1, 0},
	{0, 1, 1, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 0, 1, 0, 1, 1, 1, 0},
	{0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
	{0, 1, 1, 1, 1, 0, 1, 0, 1, 1},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0}
};

int main(void) {

    Stack *S1 = (Stack *)malloc(sizeof(Stack));
    StackInit(S1);

    while(TRUE) {


    }
}
