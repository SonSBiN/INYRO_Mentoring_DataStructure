#include <stdio.h>

#include "Stack.h"

void PrintInt(Element e)
{
    printf("%d\n", e);
}

int main(void)
{
    const int NUMS = 6;

    Stack* s = StkCreate();
    if (s) {
        for (int i = 0; i < NUMS; i++) {
            if (StkPush(s, i) == 0) {
                printf("Failed to push an element into the given stack\n");
            }
        }
        printf("전체 스택 출력\n");
        StkPrint(s, PrintInt);
        printf("스택 요소를 각각 top, pop한 후 출력\n");
        for (int i = 0; i < NUMS; i++) {
            Element e;
            if (StkTop(s, &e) == 0) {
                printf("Failed to look at the top element of the given stack\n");
            }
            else {
                printf("Top = %d\n", e);
            }
            if (StkPop(s, &e) == 0) {
                printf("Failed to pop an element from the given stack\n");
            }
            else {
                printf("Pop = %d\n", e);
            }
        }
        StkDestroy(s);
    }
    return 0;
}