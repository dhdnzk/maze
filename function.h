#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include "common.h"

enum {RIGHT = 1, DOWN, LEFT, UP, BACK};
enum {GOAL = 1, END_AT_START_LINE, ING};

#define CROSS_LEN 10
#define VERTICAL_LEN 10

typedef struct node {

  int xPos;
  int yPos;
  struct node *next;
} Node;

/* 스택에 관련된 함수들 선언 */
void NodeInit(void);     //vv 
void AddNode(int, int);      //vv
void DeleteNode(void);   //vv

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
