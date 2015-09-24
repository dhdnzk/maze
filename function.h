#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <stdio.h>
#include <stdlib.h>

enum {RIGHT = 1, DOWN, LEFT, UP, BACK};
enum {GOAL = 1, END_AT_START_LINE, ING};

#define COL_LEN 10
#define ROW_LEN 10

typedef struct _mazeBoard {
    int mazeBoard[ROW_LEN][COL_LEN]; 
    {
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
}MazeBoard;

typedef struct _position {
    int xPos;
    int yPos;
} Position;

typedef struct _node {
    struct _position *pos
    struct _node *prev;
} Node;

typedef struct _stack {
    Node *basePointer;
    Node *stackPointer;
    int numOfData;
}Stack;

/* 스택에 관련된 함수들 선언 */
void StackInit(Stack *); 
void Push(Stack *, int, int);
void Pop(Stack *); 
void Peek(Stack *);

/* 화면 출력에 관련된 함수들 선언 */
void ShowMap(MazeBoard *);

/* 움직임에 관련된 함수들 정의 */
int moving(void); 
int whereToGo(void);
void moveRight(void);
void moveLeft(void);
void moveUp(void);
void moveDown(void);
void back(void);
int calcEndOrNot(void);

#endif
