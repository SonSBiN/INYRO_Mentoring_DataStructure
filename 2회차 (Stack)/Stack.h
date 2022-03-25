#pragma once

#include "DynamicArray.h"

// 메모리가 허용하는한 크기 제한이 없는 스택 구현
typedef struct {
    DynamicArray* darr;
    int top;
} Stack;

// 스택 생성
Stack* StkCreate();

// 스택이 비어 있다면 1을 반환. 스택에 데이터가 있다면 0 반환
int StkEmpty(const Stack* stack);

// 스택에 e 추가
int StkPush(Stack* stack, Element e);

// 스택의 가장 윗부분에 있는 데이터를 pe로 저장해서 반환
// 스택의 가장 윗부분에 있는 데이터는 제거
int StkPop(Stack* stack, Element* pe);

// 스택의 가장 윗부분에 있는 데이터를 pe로 저장해서 반환
// 스택의 가장 윗부분에 있는 데이터는 제거 안함
int StkTop(const Stack* stack, Element* pe);

// 스택의 가장 윗부분에 있는 데이터부터 순서대로 화면에 출력
void StkPrint(const Stack* stack, PrintFunc func);

// 스택 제거
void StkDestroy(Stack* stack);