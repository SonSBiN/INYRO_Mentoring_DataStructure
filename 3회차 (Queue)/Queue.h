#pragma once

#include "DynamicArray.h"

typedef struct {
    DynamicArray* darr;
    int front;
    int rear;
} Queue;

Queue* QueCreate();
int QueEmpty(const Queue* queue);
int QueEnqueue(Queue* queue, Element e);
int QueDequeue(Queue* queue, Element* pe);
int QueFront(const Queue* queue, Element* pe);
void QuePrint(const Queue* queue, PrintFunc func);
void QueDestroy(Queue* queue);