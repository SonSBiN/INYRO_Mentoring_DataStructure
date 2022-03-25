#include <string.h>
//#include "vld.h"
#include "ReadPopulationData.h"
#include "List.h"

typedef struct {
    int men;
    int women;
} SUM_DATA;

const char* DATA_FILE_NAME = "SeoulPopulation2020.txt";

PopulationData PDs[3] = {
    { "종로구", 76876, 82120 }, { "은평구", 231998, 252045 }, { "강동구", 228044, 235954 }
};

void GetTotalPopulation(PopulationData* pd, void* p)
{
    SUM_DATA* sumData = (SUM_DATA*)p;
    sumData->men += pd->men;
    sumData->women += pd->women;
}

void PrintPopulationData(PopulationData pd)
{
    printf("Name: %s, Men: %d, Women: %d\n", pd.name, pd.men, pd.women);
}

void PrintPopulationData2(PopulationData* pd, void* p)
{
    printf("Name: %s, Men: %d, Women: %d\n", pd->name, pd->men, pd->women);
}

int CompareName(const PopulationData* pd1, const PopulationData* pd2)
{
    return strcmp(pd1->name, pd2->name) == 0;
}

List* CreateList(const char* fileName)
{
    FILE* f = OpenPopulationDataFile(DATA_FILE_NAME);
    if (f) {
        PopulationData pd;
        List* list = LstCreate();
        if (list) {
            int n = ReadPopulationData(f, &pd);
            while (n) {
                if (LstAddToEnd(list, pd) == 0) {
                    printf("Adding data to the list failed\n");
                    LstDestroy(list);
                    break;
                }
                n = ReadPopulationData(f, &pd);
            }
            ClosePopulationDataFile(f);
            return list;
        }
    }
    return NULL;
}

void TestDeleteNodes(List* list)
{
    PopulationData pd;

    // head 삭제
    strcpy(pd.name, "종로구");
    ListNode* node = LstFindNode(list, pd, CompareName);
    if (node) {
        LstDelete(list, node);
        printf("\n\n종로구가 삭제된 후의 리스트\n");
        LstPrint(list, PrintPopulationData);
    }

    // tail 삭제
    strcpy(pd.name, "강동구");
    node = LstFindNode(list, pd, CompareName);
    if (node) {
        LstDelete(list, node);
        printf("\n\n강동구가 삭제된 후의 리스트\n");
        LstPrint(list, PrintPopulationData);
    }

    // 중간 삭제
    strcpy(pd.name, "은평구");
    node = LstFindNode(list, pd, CompareName);
    if (node) {
        LstDelete(list, node);
        printf("\n\n은평구가 삭제된 후의 리스트\n");
        LstPrint(list, PrintPopulationData);
    }
}

void TestInsertNodes(List* list)
{
    PopulationData pd;

    // head 뒤에 삽입
    LstInsertBefore(list, list->head, PDs[0]);
    printf("\n\n종로구가 추가된 후 리스트\n");
    LstPrint(list, PrintPopulationData);

    // tail뒤에 삽입
    LstInsertAfter(list, list->tail, PDs[2]);
    printf("\n\n강동구가 추가된 후 리스트\n");
    LstPrint(list, PrintPopulationData);

    // 중간 삭제
    strcpy(pd.name, "노원구");
    ListNode* node = LstFindNode(list, pd, CompareName);
    if (node) {
        LstInsertAfter(list, node, PDs[1]);
        printf("\n\n은평구가 추가된 후 리스트\n");
        LstPrint(list, PrintPopulationData);
    }
}

int main(void)
{
    // 파일에서 데이터를 읽고, 리스트를 구성
    List* list = CreateList(DATA_FILE_NAME);
    if (list && LstEmpty(list) == 0) {
        // 완전한 리스트를 화면에 출력
        LstPrint(list, PrintPopulationData);
        // 리스트에서 세 개 요소를 삭제해보고 화면에 출력
        TestDeleteNodes(list);
        // 삭제된 요소 세 개를 다시 리스트에 추가하고 화면에 출력
        TestInsertNodes(list);     

        // 전체 남여 인구 구하기
        SUM_DATA sum = { 0, 0 };
        LstIterate(list, GetTotalPopulation, &sum);
        printf("서울시 남자 인구 숫자: %d, 서울시 여자 인구 숫자: %d\n", sum.men, sum.women);

        // LstIterate함수를 이용해서 화면에 출력하기
        printf("\nLstIterate() 함수를 이용해서 화면에 리스트 출력\n");
        LstIterate(list, PrintPopulationData2, NULL);

        // 리스트 삭제
        LstDestroy(list);
    }
    else {
        printf("리스트가 NULL이거나 요소 없음\n");
    }
    return 0;
}

