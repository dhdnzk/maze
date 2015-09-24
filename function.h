#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <stdio.h>
#include <stdlib.h>

enum {RIGHT = 1, DOWN, LEFT, UP, BACK};
enum {GOAL = 1, END_AT_START_LINE, ING};

#define COL_LEN 10
#define ROW_LEN 10

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
void StackInit(Stack *);     //vv 
void Push(Stack *, int, int);      //vv
void Pop(Stack *);   //vv
void Peek(Stack *);

/* 화면 출력에 관련된 함수들 선언 */
void showProblem(void);  //vv
void showResult(int);    //v

/* 움직임에 관련된 함수들 정의 */
int moving(void);        //vv
int whereToGo(void);     //v 체크 한번 더하기
void moveRight(void);    //v
void moveLeft(void);     //v
void moveUp(void);       //v
void moveDown(void);     //v
void back(void);         //v
int calcEndOrNot(void);  //v

#endif
