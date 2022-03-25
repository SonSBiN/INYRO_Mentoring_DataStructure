#include <stdio.h>
#include <stdlib.h>

#include "DynamicArray.h"

void PrintInt(int value)
{
    printf("%d\n", value);
}

int Sum(const DynamicArray* readData)
{
    int s = 0;
    for (int i = 0; i < DAGetCount(readData); i++) {
        Element n;
        if (DAGet(readData, i, &n)) {
            s += n;
        }
        else {
            printf("DAGet function is failed\n");
            break; // 현재까지의 합만 반환
        }
    }
    return s;
}

int ReadNumbers(DynamicArray* readData)
{
    int numRead;
    int n;
    if (readData) {
        numRead = scanf("%d", &n);
        while (numRead) {
            if (DAAdd(readData, n) == 0) {
                printf("readData에 데이터 추가 실패\n");
                return 0;
            }
            numRead = scanf("%d", &n);
        }
        return 1;
    }
    return 0;
}

int main(void)
{
    DynamicArray* readData; 

    if ((readData = DACreate())) {
        int read = ReadNumbers(readData);
        if (read) {
            int s = Sum(readData);
            printf("sum = %d, count = %d\n", s, readData->count);
            if (DAPrint(readData, PrintInt) == 0) {
                printf("Print failed\n");
            }
            printf("readData.size = %d\n", DAGetSize(readData));
            if (DADestroy(readData) == 0) {
                printf("DADestory failed\n");
            }
        }
    }
    return 0;
}