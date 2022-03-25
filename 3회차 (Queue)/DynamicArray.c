#include <stdio.h>
#include <stdlib.h>

#include "DynamicArray.h"

#define INCREMENT_SIZE 5

DynamicArray* DACreate()
{
	DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
	if (da) {
		da->arr = (Element*)malloc(sizeof(Element) * INCREMENT_SIZE);
		if (da->arr) {
			da->size = INCREMENT_SIZE;
			da->count = 0;
			return da;
		}
		else {
			free(da);
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
	if (resizableArray && resizableArray->arr) {
		if (resizableArray->count > 0 && resizableArray->count % INCREMENT_SIZE == 0) {
			resizableArray->size += INCREMENT_SIZE;
			resizableArray->arr = (Element*)realloc(resizableArray->arr, sizeof(Element) * resizableArray->size);
			if (resizableArray->arr == NULL) {
				free(resizableArray);
				return 0;
			}
		}
		resizableArray->arr[resizableArray->count] = value;
		resizableArray->count++;
		return 1;
	}
	return 0;
}

int DAPut(DynamicArray* resizableArray, int idx, Element value)
{
	if (resizableArray && resizableArray->arr 
		&& idx >= 0 && idx < resizableArray->size) {
		resizableArray->arr[idx] = value;
		return 1;
	}
	return 0;
}

int DAGet(const DynamicArray* resizableArray, int idx, Element* value)
{
	if (resizableArray && resizableArray->arr
		&& idx >= 0 && idx < resizableArray->size) {
		*value = resizableArray->arr[idx];
		return 1;
	}
	return 0;
}

int DADestroy(DynamicArray* resizableArray)
{
	if (resizableArray && resizableArray->arr) {
		free(resizableArray->arr);
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