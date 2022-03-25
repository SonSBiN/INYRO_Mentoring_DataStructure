#include <stdio.h>
#include "ReadPopulationData.h"

FILE* OpenPopulationDataFile(const char* fileName)
{
    if (fileName) {
        FILE* f = fopen(fileName, "rt");
        return f;
    }
    return NULL;
}

void ClosePopulationDataFile(FILE* f)
{
    if (f) {
        fclose(f);
    }
}

int ReadPopulationData(FILE* f, PopulationData* p)
{
    if (f && p) {
        int n = fscanf(f, "%s %d %d", p->name, &p->men, &p->women);
        return n == 3;
    }
    return 0;
}