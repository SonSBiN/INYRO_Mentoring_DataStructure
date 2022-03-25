#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

PTreeNode TreCreateNode(Element e)
{
    return TreCreateNode2(e, NULL, NULL);
}

PTreeNode TreCreateNode2(Element e, PTreeNode left, PTreeNode right)
{
    PTreeNode node = (PTreeNode)malloc(sizeof(TreeNode));
    if (node) {
        node->data = e;
        node->left = left;
        node->right = right;
    }
    return node;
}

void TreDestroy(PTreeNode root)
{
    if (root) {
        TreDestroy(root->left);
        root->left = NULL;
        TreDestroy(root->right);
        root->right = NULL;
        if (root->left == NULL && root->right == NULL) {
            free(root);
        }
    }
}

// IteratorFunc를 list의 각 요소에 적용. func()함수에 p를 인자로 전달
void TreIterate(PTreeNode root, IterateFunc func, void* p, TreeTraverseOrder order)
{
    if (root) {
        if (order == TTO_PREORDER) {
            func(&(root->data), p);
            TreIterate(root->left, func, p, order);
            TreIterate(root->right, func, p, order);
        }
        else if (order == TTO_INORDER) {
            TreIterate(root->left, func, p, order);
            func(&(root->data), p);
            TreIterate(root->right, func, p, order);
        }
        else if (order == TTO_POSTORDER) {
            TreIterate(root->left, func, p, order);
            TreIterate(root->right, func, p, order);
            func(&(root->data), p);
        }
    }
}

