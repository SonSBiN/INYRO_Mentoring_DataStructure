#pragma once

#include <stdio.h>
#include "PopulationData.h"

FILE* OpenPopulationDataFile(const char* fileName);
void ClosePopulationDataFile(FILE* f);
int ReadPopulationData(FILE* f, PopulationData* p);