#include <stdio.h>
#include <stdlib.h>

#include "DynamicArray.h"

#define INCREMENT_SIZE 5

DynamicArray* DACreate()
{
    DynamicArray* resizableArray = (DynamicArray*) malloc(sizeof(DynamicArray));
    if (resizableArray) {
        resizableArray->arr = (int*)malloc(INCREMENT_SIZE * sizeof(Element));
        if (resizableArray->arr) {
            resizableArray->size = INCREMENT_SIZE;
            resizableArray->count = 0;
            return resizableArray;
        }
    }
    return NULL;
}

int DAGetCount(const DynamicArray* resizableArray)
{
    if (resizableArray) {
        return resizableArray->count;
    }
    return -1;
}

int DAGetSize(const DynamicArray* resizableArray)
{
    if (resizableArray) {
        return resizableArray->size;
    }
    return -1;
}

int DAAdd(DynamicArray* resizableArray, Element value)
{
    if (resizableArray) {
        if (resizableArray->count == resizableArray->size) {
            resizableArray->size += INCREMENT_SIZE;
            resizableArray->arr = realloc(resizableArray->arr, resizableArray->size * sizeof(int));
            if (resizableArray->arr == NULL) return 0;
        }
        resizableArray->arr[resizableArray->count] = value;
        resizableArray->count++;
        return 1;
    }
    return 0;
}

int DAPut(DynamicArray* resizableArray, int idx, Element value)
{
    if (resizableArray && idx < resizableArray->size) {
        resizableArray->arr[idx] = value;
        return 1;
    }
    return 0;
}

int DAGet(const DynamicArray* resizableArray, int idx, Element* value)
{
    if (resizableArray && idx < resizableArray->count) {
        *value = resizableArray->arr[idx];
        return 1;
    }
    return 0;
}

int DADestroy(DynamicArray* resizableArray)
{
    if (resizableArray && resizableArray->arr) {
        free(resizableArray->arr);
        resizableArray->arr = NULL;
        resizableArray->size = 0;
        resizableArray->count = 0;
        free(resizableArray);
        return 1;
    }
    return 0;
}

int DAPrint(const DynamicArray* resizableArray, PrintFunc printFunc)
{
    if (resizableArray && resizableArray->arr) {
        for (int i = 0; i < resizableArray->count; i++) {
            //printf("%d\n", resizableArray->arr[i]);
            printFunc(resizableArray->arr[i]);
        }
        return 1;
    }
    return 0;
}