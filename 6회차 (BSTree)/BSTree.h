#pragma once

#include "Tree.h"

typedef int (*CompareElement)(Element* e1, Element* e2);

PTreeNode BSTreInsert(PTreeNode root, Element e, CompareElement compare);
PTreeNode BSTreDelete(PTreeNode root, Element e, CompareElement compare);
PTreeNode BSTreSearch(PTreeNode root, Element e, CompareElement compare);
