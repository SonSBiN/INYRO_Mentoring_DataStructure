#pragma once

#include <stdlib.h>

// DynamicArray에 저장될 배열 요소의 자료형
typedef int Element;

typedef struct {
    Element* arr; // 배열 주소 저장
    int count; // 현재 인덱스 번호 저장
    int size;  // 배열의 크기 저장
} DynamicArray;

// Element에 해당되는 자료를 화면에 출력하는 함수들을 대표하는 자료형
typedef void(*PrintFunc)(Element e);

// DynamicArray의 생성
DynamicArray* DACreate();
// DynamicArray의 빈 자리에 value를 추가
int DAAdd(DynamicArray* resizableArray, Element value);
// DynamicArray의 idx 인덱스 위치에 value 값을 저장
int DAPut(DynamicArray* resizableArray, int idx, Element value);
// DynamicArray에서 idx 인덱스에 해당되는 요소 값을 value 변수를 통해서 반환
int DAGet(const DynamicArray* resizableArray, int idx, Element* value);
// DynamicArray에 있는 데이터 개수 반환
// 문제가 있으면 -1 반환
int DAGetCount(const DynamicArray* resizableArray);
// DynamicArray에서 할당된 전체 배열의 크기 반환
// 문제가 있으면 -1 반환
int DAGetSize(const DynamicArray* resizableArray);
// DynamicArray에 할당된 배열 및 DynamicArray 구조체 해제
int DADestroy(DynamicArray* resizableArray);
// DynamicArray에 있는 요소들을 printFunc를 이용해서 화면에 출력
int DAPrint(const DynamicArray* resizableArray, PrintFunc printFunc);