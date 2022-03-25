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
    { "���α�", 76876, 82120 }, { "����", 231998, 252045 }, { "������", 228044, 235954 }
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

    // head ����
    strcpy(pd.name, "���α�");
    ListNode* node = LstFindNode(list, pd, CompareName);
    if (node) {
        LstDelete(list, node);
        printf("\n\n���α��� ������ ���� ����Ʈ\n");
        LstPrint(list, PrintPopulationData);
    }

    // tail ����
    strcpy(pd.name, "������");
    node = LstFindNode(list, pd, CompareName);
    if (node) {
        LstDelete(list, node);
        printf("\n\n�������� ������ ���� ����Ʈ\n");
        LstPrint(list, PrintPopulationData);
    }

    // �߰� ����
    strcpy(pd.name, "����");
    node = LstFindNode(list, pd, CompareName);
    if (node) {
        LstDelete(list, node);
        printf("\n\n���򱸰� ������ ���� ����Ʈ\n");
        LstPrint(list, PrintPopulationData);
    }
}

void TestInsertNodes(List* list)
{
    PopulationData pd;

    // head �ڿ� ����
    LstInsertBefore(list, list->head, PDs[0]);
    printf("\n\n���α��� �߰��� �� ����Ʈ\n");
    LstPrint(list, PrintPopulationData);

    // tail�ڿ� ����
    LstInsertAfter(list, list->tail, PDs[2]);
    printf("\n\n�������� �߰��� �� ����Ʈ\n");
    LstPrint(list, PrintPopulationData);

    // �߰� ����
    strcpy(pd.name, "�����");
    ListNode* node = LstFindNode(list, pd, CompareName);
    if (node) {
        LstInsertAfter(list, node, PDs[1]);
        printf("\n\n���򱸰� �߰��� �� ����Ʈ\n");
        LstPrint(list, PrintPopulationData);
    }
}

int main(void)
{
    // ���Ͽ��� �����͸� �а�, ����Ʈ�� ����
    List* list = CreateList(DATA_FILE_NAME);
    if (list && LstEmpty(list) == 0) {
        // ������ ����Ʈ�� ȭ�鿡 ���
        LstPrint(list, PrintPopulationData);
        // ����Ʈ���� �� �� ��Ҹ� �����غ��� ȭ�鿡 ���
        TestDeleteNodes(list);
        // ������ ��� �� ���� �ٽ� ����Ʈ�� �߰��ϰ� ȭ�鿡 ���
        TestInsertNodes(list);     

        // ��ü ���� �α� ���ϱ�
        SUM_DATA sum = { 0, 0 };
        LstIterate(list, GetTotalPopulation, &sum);
        printf("����� ���� �α� ����: %d, ����� ���� �α� ����: %d\n", sum.men, sum.women);

        // LstIterate�Լ��� �̿��ؼ� ȭ�鿡 ����ϱ�
        printf("\nLstIterate() �Լ��� �̿��ؼ� ȭ�鿡 ����Ʈ ���\n");
        LstIterate(list, PrintPopulationData2, NULL);

        // ����Ʈ ����
        LstDestroy(list);
    }
    else {
        printf("����Ʈ�� NULL�̰ų� ��� ����\n");
    }
    return 0;
}

