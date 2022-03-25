#pragma once

#include "DAType.h"

typedef struct _Node {
    Element element;
    struct _Node* next;
} ListNode;

typedef struct {
    ListNode* head; // 가장 첫 번째 노드를 가리킴
    ListNode* tail; // 가장 마지막 노드를 가리킴
} List;

typedef void (*PrintFunc)(Element e);

// e1과 e2가 동일하면 1을 반환하고 아니면 0을 반환
typedef int (*CompareFunc)(const Element* e1, const Element* e2);

typedef void (*IterateFunc)(Element* e, void* p);

// List를 생성한 후 반환. 동적 할당이 제대로 안되면 NULL반환
List* LstCreate();

// 리스트에 요소가 있으면 0, 없으면 1을 반환
int LstEmpty(const List* list);

// list의 마지막 요소로 e를 삽입. ListNode를 새로 동적 할당함
// 추가에 성공하면 1 반환. 아니면 0 반환
int LstAddToEnd(List* list, Element e);

// list의 첫 번째 요소로 e를 삽입. ListNode를 새로 동적 할당함
// 추가에 성공하면 1 반환. 아니면 0 반환
int LstAddToFront(List* list, Element e);

// list에 next노드가 있다면, next 앞에 e를 삽입. 성공하면 1, 실패하면 0을 반환
// list에 next가 없으면 0 반환
int LstInsertBefore(List* list, ListNode* next, Element e);

// list에 next노드가 있다면, previous 뒤에 e를 삽입. 성공하면 1, 실패하면 0을 반환
// list에 previous가 없으면 0 반환
int LstInsertAfter(List* list, ListNode* previous, Element e);

// func를 이용해서 list의 모든 요소를 출력
void LstPrint(List* list, PrintFunc func);

// list에서 node를 삭제. 성공하면 1을 반환. 실패하면 0을 반환
int LstDelete(List* list, ListNode* node);

// list에서 e를 검색해서 있으면 e를 해당 노드를 반환. Element를 비교하는 것은 CompareFunc를 이용
// 만약 해당 노드가 없으면 NULL 반환
ListNode* LstFindNode(List* list, Element e, CompareFunc func);

// IteratorFunc를 list의 각 요소에 적용. func()함수에 p를 인자로 전달
void LstIterate(List* list, IterateFunc func, void* p);

// list에 있는 모든 요소를 삭제하고 동적 할당된 메모리 해제
void LstDestroy(List* list);

