#include "function.h"

/* 스택에 관련된 함수들 정의 */
void StackInit(Stack *pStack) {
    pStack->basePointer = (Stack *)malloc(sizeof(Stack));
    pStack->basePointer->prev = NULL;
    pStack->basePointer->pos = NULL;
    pStack->stackPointer = pStack->stackPointer;
    pStack->numOfData = 0;
}

void Push(Stack *pStack, int y, int x) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Position *newPos = (Position *)malloc(sizeof(Position));
    newPos->yPos = y;
    newPos->xPos = x;
    newNode->pos = newPos;
    newNode->prev = pStack->stackPointer;
    pStack->stackPointer = newNode; 
    ( pStack->numOfData )++;
}

Position Pop(Stack *pStack) {
    if( pStack->numOfData == 0 ) {
        printf("there is no data to return!\n");
        return NULL;
    }
    else {
    Position ret;
    Node *tmpNode;
    ret.xPos = pStack->stackPointer->pos->xPos;
    ret.yPos = pStack->stackPointer->pos->yPos;
    free(pStack->stackPointer->pos); 
    tmpNode = pStack->stackPointer;
    pStack->stackPointer = pStack->stackPointer->prev;
    free(tmpNode);
    (pStack->numOfData )--;
    return ret;

    }
}

Position Peek(Stack *pStack) {
    if ( pStack->numOfData == 0 ) {
        printf("there is no data to return!\n");
        return NULL;
    }
    else {
        Position ret;
        ret.xPos = pStack->stackPointer->pos->xPos; 
        ret.yPos = pStack->stackPointer->pos->yPos; 
        return ret;
    }
}
    

/* 화면 출력에 관련된 함수들 정의 */
void ShowMap(MazeBoard *map) {
    int i, j;
    printf("----------------------\n");
    for(i = 0; i < ROW_LEN i++) {
        printf("|");
        for(j = 0; j < COL_LEN; j++) {
            if(map->mazeBoard[i][j] == 1) {
                printf("ㅁ");
            }
            else {
                printf("  ");
            }
        }
        printf("|\n");
    }
    printf("----------------------\n");
}

void showResult(Stack *pStack) {
    

}


/* 움직임에 관련된 함수들 정의 */
int moving(void) {

  switch(whereToGo()) {

  case RIGHT:
    moveRight();
    break;

  case DOWN:
    moveDown();
    break;

  case LEFT:
    moveLeft();
    break;

  case UP:
    moveUp();
    break;

  case BACK:
    back();
    break;
  }

  sleep(10);

  return calcEndOrNot();
}


int whereToGo(void) {
   //오른쪽으로 갈 수 있으면
   if(mazeBoard[head->next->yPos][head->next->xPos + 1] == 0) {
   return 1;
   }

   //아래로 갈 수 있으면
   else if(mazeBoard[head->next->yPos + 1][head->next->xPos] == 0) {
   return 2;
   }

   //왼쪽으로 갈 수 있으면
   else if(mazeBoard[head->next->yPos][head->next->xPos - 1] == 0) {
   return 3;
   }

   //위로 갈 수 있으면
   else if(mazeBoard[head->next->yPos - 1][head->next->xPos] == 0) {
   return 4;
   }

   //다 아니면 뒤로
   else {
   return 5;
   }
}

void moveRight(void) {

    mazeBoard[head->next->yPos][head->next->xPos] = 2; 

    AddNode( (head->next->yPos), (head->next->xPos + 1) );
    numOfMove ++;
    printf("오른쪽으로 이동합니다.\n");
    printf("이동 횟수 : %d\n", numOfMove);
}

void moveDown(void) {

    mazeBoard[head->next->yPos][head->next->xPos] = 2; 
    AddNode( (head->next->yPos + 1), (head->next->xPos) );
    numOfMove ++;
    printf("아래로 이동합니다.\n");
    printf("이동 횟수 : %d\n", numOfMove);
}

void moveLeft(void) {

    mazeBoard[head->next->yPos][head->next->xPos] = 2; 
    AddNode( (head->next->yPos), (head->next->xPos - 1) );
    numOfMove ++;
    printf("왼쪽으로 이동합니다.\n");
    printf("이동 횟수 : %d\n", numOfMove);
}

void moveUp(void) {

    mazeBoard[head->next->yPos][head->next->xPos] = 2; 
    AddNode( (head->next->yPos - 1), (head->next->xPos) );
    numOfMove ++;
    printf("위로 이동합니다.\n");
    printf("이동 횟수 : %d\n", numOfMove);
}

void back(void) {

    mazeBoard[head->next->yPos][head->next->xPos] = -1;
    DeleteNode();
    numOfMove ++;
    printf("뒤로 한칸 돌아갑니다.\n");
    printf("이동 횟수 : %d\n", numOfMove);
}

int calcEndOrNot(void) {

    if (head->next->yPos == 9 && head->next->xPos == 9) {
        printf("calcEndOrNot 함수에서 골 반환\n");
        return 1;
    }
    else if (head ->next->yPos == 0 && head->next->xPos == 0) {
        if (mazeBoard[0][1] != 0 && mazeBoard[1][0] != 0) {
            printf("calcEndOrNot 함수에서 스타트라인에서 끝 반환\n");
            return 2;
        }
        else {
            printf("calcEndOrNot함수에서 ING 반환\n");
            return 3;
        }
    }
}
