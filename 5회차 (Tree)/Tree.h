#pragma once

#include <stdlib.h>
#include "DAType.h"

typedef struct _Node {
    Element data;
    struct _Node* left;
    struct _Node* right;
} TreeNode;

typedef TreeNode* PTreeNode;

typedef enum { TTO_PREORDER, TTO_INORDER, TTO_POSTORDER } TreeTraverseOrder;

typedef void(*IterateFunc)(Element* e, void* p);

PTreeNode TreCreateNode(Element e);
PTreeNode TreCreateNode2(Element e, PTreeNode left, PTreeNode right);
void TreDestroy(PTreeNode root);
// IteratorFunc를 list의 각 요소에 적용. func()함수에 p를 인자로 전달
void TreIterate(PTreeNode root, IterateFunc func, void* p, TreeTraverseOrder order);
